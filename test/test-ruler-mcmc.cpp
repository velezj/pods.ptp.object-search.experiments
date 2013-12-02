
#include <p2l-rawseeds-experiments/register.hpp>
#include <point-process-experiment-core/experiment_utils.hpp>
#include <point-process-experiment-core/experiment_runner.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


using namespace math_core;
using namespace point_process_experiment_core;
using namespace point_process_core;


int main( int argc, char** argv )
{
  
  rawseeds_experiments::rawseeds_registration_type::register_experiments();


  // get the world to test
  std::vector<nd_point_t> groundtruth = groundtruth_for_world( "rawseeds::small_001" );
  nd_aabox_t window = window_for_world( "rawseeds::small_001" );
 
  // the number of iterations to do
  size_t num_samples = 1000;
  
  // test all known models
  for( auto model_id : get_registered_models() ) {

    // get hte mode to test
    boost::shared_ptr<mcmc_point_process_t> model = get_model_by_id( model_id, window );

    // ope na new file for the trace of distances
    std::ostringstream oss;
    oss << "test_ruler_mcmc_dist-" << model_id << ".txt";
    std::ofstream fout( oss.str() );

    // ok, now add some observations to the model,
    // all of the ground truth and all empty regions
    double model_res = 1.0;
    marked_grid_t<bool> grid = point_set_as_grid( groundtruth, window, model_res );
    model->add_observations( groundtruth );
    for( auto cell : grid.all_cells() ) {
      if( (*grid( cell )) == true ) {
      } else {
	model->add_negative_observation( grid.region( cell ) );
      }
    }

    // ok, sample using MCMC and check distances to ground truth
    for( size_t i = 0; i < num_samples; ++i ) {
      
      std::vector<nd_point_t> sample = model->sample_and_step();
      marked_grid_t<bool> grid_sample = point_set_as_grid( sample, window, model_res );
      double dist = marked_grid_distance( grid, grid_sample );
      std::cout << "[ " << i << " / " << num_samples << " ] " << dist << std::endl;
      fout << dist << std::endl;
      
    }

  }
  
}
