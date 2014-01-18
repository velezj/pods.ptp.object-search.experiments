
#include <p2l-rawseeds-experiments/register.hpp>
#include <point-process-experiment-core/experiment_utils.hpp>
#include <point-process-experiment-core/experiment_runner.hpp>
#include <iostream>
#include <sstream>
#include <ctime>
#include <boost/exception/diagnostic_information.hpp>


int main( int argc, char** argv ) {

  rawseeds_experiments::rawseeds_registration_type::register_experiments();

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
  

  // read inthe id for the world, model, and planner
  std::string world, model, planner;
  std::cout << "World> ";
  std::cin >> world;
  std::cout << "Model> ";
  std::cin >> model;
  std::cout << "Planner> ";
  std::cin >> planner;
  
  // get settings
  bool add_empty_regions;
  double initial_window_fraction;
  bool centered_window;
  double fraction;
  std::string experiment_id;
  size_t num_runs = 1;
  std::cout << "Add Empty Regions [0/1]> ";
  std::cin >> add_empty_regions;
  std::cout << "Initial Window Fraction> ";
  std::cin >> initial_window_fraction;
  std::cout << "Window Centered [0/1]> ";
  std::cin >> centered_window;
  std::cout << "Fraction to find> ";
  std::cin >> fraction;
  std::cout << "Experiment Id [. for timestamp]> ";
  std::cin >> experiment_id;
  if( experiment_id == "." ) {
    std::ostringstream oss;
    oss << "ex-" << time( NULL );
    experiment_id = oss.str();
    std::cout << "Setting Experiment Id to: " << experiment_id << std::endl;
  }
  std::cout << "Number of runs> ";
  std::cin >> num_runs;

  std::string base_experiment_id = experiment_id;
  
  try {
    
    for( size_t i = 0; i < num_runs; ++i ) {
      
      // create the runs experiment id if wanted
      if( num_runs > 1 ) {
	std::ostringstream oss;
	oss << base_experiment_id << "-" << i;
	experiment_id = oss.str();
      }
      
      // run the experiment
      point_process_experiment_core::run_experiment( world,
						     model,
						     planner,
						     add_empty_regions,
						     initial_window_fraction,
						     centered_window,
						     fraction,
						     experiment_id);
    }
  } catch ( ... ) {
    std::cout << "EXCEPTION: " << std::endl;
    std::cout << boost::current_exception_diagnostic_information();
  }
    
}
