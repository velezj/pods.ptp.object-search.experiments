
#include <p2l-rawseeds-experiments/register.hpp>
#include <point-process-experiment-core/experiment_utils.hpp>
#include <point-process-experiment-core/experiment_runner.hpp>
#include <iostream>
#include <sstream>
#include <ctime>


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
  std::string experiment_id;
  std::cout << "Add Empty Regions [0/1]> ";
  std::cin >> add_empty_regions;
  std::cout << "Initial Window Fraction> ";
  std::cin >> initial_window_fraction;
  std::cout << "Experiment Id [Empty for timestamp]> ";
  std::cin >> experiment_id;
  if( experiment_id == "" ) {
    std::ostringstream oss;
    oss << "ex-" << time( NULL );
    experiment_id = oss.str();
    std::cout << "Setting Experiment Id to: " << experiment_id << std::endl;
  }
  
  // run the experiment
  point_process_experiment_core::run_experiment( world,
						 model,
						 planner,
						 add_empty_regions,
						 initial_window_fraction,
						 experiment_id );
  
}
