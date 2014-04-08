
#include <p2l-rawseeds-experiments/register.hpp>
#include <point-process-experiment-core/experiment_utils.hpp>
#include <point-process-experiment-core/experiment_runner.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <boost/exception/diagnostic_information.hpp>
#include <erf-couchdb/couchdb.hpp>
#include <git-version-script/git_version.hpp>



namespace po = boost::program_options;
using namespace boost::property_tree;


int main( int argn, char** argv )
{

  rawseeds_experiments::rawseeds_registration_type::register_experiments();


  // setup the program options
  po::options_description po_desc( "RAWSEEDS Experiment Runner Options" );
  po_desc.add_options()
    ( "help", "usage and help message")
    ( "world", 
      po::value<std::string>(), 
      "Which RAWSEEDS world to load.")
    ( "planner",
      po::value<std::string>(),
      "Which planner should we use.")
    ( "model",
      po::value<std::string>(),
      "Which point process to use for modeling and exploration." )
    ( "add-empty-regions",
      po::value<bool>(),
      "Compute and add emty regions within observed cells")
    ( "centered-window",
      po::value<bool>(),
      "Is the initial window centered?")
    ( "initial-window-fraction",
      po::value<double>(),
      "The fraction of the world window initially 'seen' by the planner")
    ( "goal-fraction-found",
      po::value<double>(),
      "The fraction of the groundtruth point we need to find to finish the run")
    ( "experiment-id",
      po::value<std::string>(),
      "The experiment id")
    ( "results-database-url",
      po::value<std::string>()->default_value("http://localhost:5984/rawseeds-experiment-results/"),
      "The CouchDB url to use as the results database");
  

  // parse the program options
  po::variables_map po_vm;
  po::store( po::parse_command_line( argn, argv, po_desc ), po_vm );
  po::notify( po_vm );
  
  // show usage if wanted
  if( po_vm.count( "help" )) {
    std::cout << po_desc << std::endl;
    std::cout << "Worlds: " << std::endl;
    for( auto item : point_process_experiment_core::get_registered_worlds() ) {
      std::cout << "    " << item << std::endl;
    }
    std::cout << "Models: " << std::endl;
    for( auto item : point_process_experiment_core::get_registered_models() ) {
      std::cout << "    " << item << std::endl;
    }
    std::cout << "Planners: " << std::endl;
    for( auto item : point_process_experiment_core::get_registered_planners() ) {
      std::cout << "    " << item << std::endl;
    }
    return 1;
  }


  // get the settings from the options
  std::string world, model, planner;
  bool add_empty_regions;
  double initial_window_fraction;
  bool centered_window;
  double fraction;
  std::string experiment_id;
  world = po_vm["world"].as<std::string>();
  model = po_vm["model"].as<std::string>();
  planner = po_vm["planner"].as<std::string>();
  add_empty_regions = po_vm["add-empty-regions"].as<bool>();
  initial_window_fraction = po_vm["initial-window-fraction"].as<double>();
  centered_window = po_vm["centered-window"].as<bool>();
  fraction = po_vm["goal-fraction-found"].as<double>();
  experiment_id = po_vm["experiment-id"].as<std::string>();

  std::vector<point_process_core::marked_grid_cell_t> trace;
  double seconds_taken = std::numeric_limits<double>::quiet_NaN();
  try {
    
    // run the experiment
    clock_t start_clock = clock();
    trace = 
      point_process_experiment_core::run_experiment( world,
						     model,
						     planner,
						     add_empty_regions,
						     initial_window_fraction,
						     centered_window,
						     fraction,
						     experiment_id);
    clock_t end_clock = clock();
    seconds_taken = ( (double)( end_clock - start_clock ) / CLOCKS_PER_SEC );

  } catch ( ... ) {
    std::cout << "EXCEPTION running experiment: " << std::endl;
    std::cout << boost::current_exception_diagnostic_information();
    return -1;
  }


  try {

    // store results in couchdb
    couchdb::Couchdb couch( boost::network::uri::uri(po_vm["results-database-url"].as<std::string>()) );
    
    // create a document for the result
    ptree result;
    
    // add the code git version
    result.put_child
      ( "code.version", 
	git_version::git_version( "/home/velezj/projects/gits/p2l-system/" ) );
    
    // add the parameters for the experiment
    result.put( "result.parameters.model_id", model );
    result.put( "result.parameters.world_id", world );
    result.put( "result.parameters.planner_id", planner );
    result.put( "result.parameters.add_empty_regions", add_empty_regions );
    result.put( "result.parameters.initial_window_fraction", initial_window_fraction );
    result.put( "result.parameters.centered_window", centered_window );
    result.put( "result.parameters.goal_fraction_to_find", fraction );
    result.put( "result.parameters.experiment_id", experiment_id );

    // add the trace for the experiment
    for( size_t i = 0; i < trace.size(); ++i ) {
      point_process_core::marked_grid_cell_t cell = trace[i];
      std::ostringstream oss;
      oss << cell;
      result.add( "result.trace.", oss.str() );
    }

    // add the time taken to compute
    result.put( "runtime.seconds", seconds_taken );

    // save the document
    couch.save( result );
    

  } catch( ... ) {
    std::cout << "EXCEPTION storing results: " << std::endl;
    std::cout << boost::current_exception_diagnostic_information();
    return -2;
  }
  
  return 0;
}
