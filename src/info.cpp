

#include <object-search.rawseeds-experiments/register.hpp>
#include <point-process-experiment-core/experiment_utils.hpp>
#include <point-process-core/marked_grid.hpp>
#include <math-core/io.hpp>
#include <boost/program_options.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <boost/exception/diagnostic_information.hpp>
#include <erf-couchdb/couchdb.hpp>


namespace po = boost::program_options;
using namespace boost::property_tree;
using namespace math_core;
using namespace point_process_experiment_core;
using namespace point_process_core;


nd_point_t parse_point( std::istream& is ) {
  char c;
  double d;
  nd_point_t point;
  is >> c;
  while( c != ')' && is ) {
    is >> d;
    point.coordinate.push_back(d);
    point.n = point.coordinate.size();
    is >> c;
  }
  return point;
}

marked_grid_cell_t parse_cell( std::istream& is ) {
  char c;
  unsigned long l;
  marked_grid_cell_t cell;
  is >> c >> c >> c >> c >> c;
  while( c != '}' && is ) {
    is >> l;
    cell.coordinate.push_back(l);
    cell.n = cell.coordinate.size();
    is >> c;
  }
  return cell;
}


int main( int argn, char** argv )
{

  rawseeds_experiments::rawseeds_registration_type::register_experiments();
  
    // setup the program options
  po::options_description po_desc( "RAWSEEDS Experiment Runner Options" );
  po_desc.add_options()
    ( "help", "usage and help message")
    ( "result",
      po::value<std::string>(),
      "The couchdb result id to query" )
    ( "results-database-url",
      po::value<std::string>()->default_value("http://localhost:5984/rawseeds-experiment-results/"),
      "The CouchDB url to use as the results database")
    ( "trace",
      po::value<bool>()->default_value(true),
      "returns the trace of the result" )
    ( "json",
      po::value<bool>()->default_value(true),
      "result is in JSON format" );
  
    // parse the program options
  po::variables_map po_vm;
  po::store( po::parse_command_line( argn, argv, po_desc ), po_vm );
  po::notify( po_vm );
  
  // show usage if wanted
  if( po_vm.count( "help" )) {
    std::cout << po_desc << std::endl;
    return 1;
  }


  try {

    // get the result form couchdb
    couchdb::Couchdb couch( po_vm["results-database-url"].as<std::string>() );
    ptree result = couch.fetch( po_vm["result"].as<std::string>() );
      
    // load the world points
    std::string world_id = result.get<std::string>( "result.parameters.world.id" );
    std::vector<math_core::nd_point_t> gt = groundtruth_for_world( world_id );
    //std::cout << "total points: " << gt.size() << std::endl;
    
    // load the planner's grid
    std::istringstream start_ss( result.get<std::string>( "result.parameters.planner.grid.window.start" ) );
    std::istringstream end_ss( result.get<std::string>( "result.parameters.planner.grid.window.end" ) );
    double res = result.get_child( "result.parameters.planner.grid.resolution" ).begin()->second.get_value<double>();
    nd_point_t start = parse_point( start_ss );
    nd_point_t end = parse_point( end_ss );
    nd_aabox_t window = aabox( start, end );
    marked_grid_t<unsigned long> trace_grid( window, res );

    // put points on grid
    for( auto p : gt ) {
      if( trace_grid( p ) ) {
	trace_grid.set( p, *trace_grid(p) + 1 );
      } else {
	trace_grid.set( p, 1 );
      }
    }

    std::vector<unsigned long> trace_count;
    unsigned long count = 0;

    // grab the initial window and the initial observation count
    // Grab the cell in hte planner's visited grid which are inside of the 
    // initial window
    double initial_window_fraction = result.get<double>( "result.parameters.initial_window_fraction" );
    nd_aabox_t world_window = window_for_world( world_id );
    bool initial_window_is_centered = result.get<std::string>( "result.parameters.centered_window" ) == "true" ? true : false;
    nd_aabox_t initial_window = 
      aabox( world_window.start, 
	     world_window.start + ( world_window.end - world_window.start ) * initial_window_fraction );
    if( initial_window_is_centered ) {
      nd_vector_t shift = 0.5 * ( world_window.end - initial_window.end );
      initial_window = aabox( initial_window.start + shift,
			      initial_window.end + shift );
    }
    std::vector<marked_grid_cell_t> cells 
      = cells_fully_inside_window( trace_grid,
				   initial_window );
    nd_aabox_t actual_window = enclosing_window_for_cells( trace_grid, cells );
    std::vector<nd_point_t> seen_points;
    if( !undefined(actual_window) ) {
      seen_points = points_inside_window(actual_window,gt);
    }
    count = seen_points.size();
    //std::cout << "count=" << count << " fraction=" << initial_window_fraction << " centered=" << initial_window_is_centered << " window: " << window << " " << initial_window << " " << actual_window << " #cells=" << cells.size() << std::endl;

    
    // ok, loop over the trace
    for( auto v : result.get_child("result.trace") ) {
      std::istringstream cell_ss( v.second.data() );
      marked_grid_cell_t cell = parse_cell( cell_ss );
      if( trace_grid( cell ) ) {
	count += (*trace_grid(cell));
      }
      trace_count.push_back( count );
    }

    // print out the trace count
    if( po_vm["json"].as<bool>() ) {
      ptree output;
      for( auto c : trace_count ) {
	output.add( "trace.", c );
      }
      json_parser::write_json( std::cout, output, false );
    } else {
      std::cout << "trace = ";
      for( auto c : trace_count ) {
	std::cout << c << ",";
      }
      std::cout << std::endl;
    }

  } catch( ... ) {
    std::cout << "EXCEPTION: " << std::endl;
    std::cout << boost::current_exception_diagnostic_information();
    return -1;
  }

  return 0;
}
