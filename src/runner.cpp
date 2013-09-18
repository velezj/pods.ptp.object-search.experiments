
#include "data_loader.hpp"
#include <ruler-point-process/ruler_point_process.hpp>
#include <planner-core/shortest_path_next_planner.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <boost/shared_ptr.hpp>


using namespace math_core;
using namespace point_process_experiment_core;
using namespace planner_core;
using namespace point_process_core;
using namespace rawseeds_experiments;
namespace po = boost::program_options;


int main( int argn, char** argv )
{

  // setup the program options
  po::options_description po_desc( "RAWSEEDS Experiment Runner Options" );
  po_desc.add_options()
    ( "help", "usage and help message")
    ( "world", 
      po::value<std::string>()->default_value( "biccoca_2009_02_27a" ), 
      "Which RAWSEEDS world to load. Current supported values are ['biccoca_2009_02_27a']")
    ( "window", 
      po::value<nd_aabox_t>()->default_value(nd_aabox_t()),
      "What window/bounds to use fo the world. By default uses the window for the world specified." )
    ( "planner",
      po::value<std::string>()->default_value( "shortest_path_next_planner" ),
      "Which planner should we use. Current supported planners are ['shortest_path_next_planner']")
    ( "planner-parameters-json",
      po::value<std::string>()->default_value( "" ),
      "The parameters for the planner as a JSON string")
    ( "point-process",
      po::value<std::string>()->default_value( "ruler_point_process" ),
      "Which point process to use for modeling and exploration. Current supported point processes are: ['ruler_point_process', 'igmm', 'poisson' ]" )
    ( "point-process-parameters-json",
      po::value<std::string>()->default_value(""),
      "The point process parameters as a JSON string");
      

  // parse the program options
  po::variable_map po_vm;
  po::store( po::parse_command_line( argn, argv, po_desc ), po_vm );
  po::notify( po_vm );
  
  // show usage if wanted
  if( po_vm.count( "help" )) {
    std::cout << desc << std::endl;
    return 1;
  }

  // get the wanted world points and window
  std::vector< nd_point_t > ground_truth = groundtruth_for_world( po_vm["world"].as<std::string>() );
  nd_aabox_t world_window = po_vm[ "window" ].as<nd_aabox_t>();
  if( undefined( world_window ) ) {
    world_window = window_for_world( po_vm["world"] );
  }

  // build up the 
}
