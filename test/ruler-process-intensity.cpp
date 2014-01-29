
#include <p2l-rawseeds-experiments/register.hpp>
#include <point-process-experiment-core/experiment_utils.hpp>
#include <point-process-experiment-core/experiment_runner.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>


using namespace math_core;
using namespace point_process_experiment_core;
using namespace point_process_core;


int main( int argc, char** argv )
{
  
  rawseeds_experiments::rawseeds_registration_type::register_experiments();


  // get the world to test
  std::vector<nd_point_t> groundtruth = groundtruth_for_world( "rawseeds::biccoca_2009_02_27a" );
  nd_aabox_t window = window_for_world( "rawseeds::biccoca_2009_02_27a" );

  std::vector<std::string> models{ 
    "rawseeds::igmm_2d_weak_001",
      "rawseeds::ruler_2d_mean_006",
      "rawseeds::ruler_2d_mean_007",
      "rawseeds::ruler_2d_mean_008",
      };
  
  // test all known models
  for( auto model_id : models ) {

    std::cout << "testing model: " << model_id << std::endl;

    // get the mode to test
    boost::shared_ptr<mcmc_point_process_t> model = get_model_by_id( model_id, window,groundtruth );

    // ok, now add some observations to the model,
    // all of the ground truth and all empty regions
    double model_res = 10.0;
    marked_grid_t<bool> grid = point_set_as_grid( groundtruth, window, model_res );
    model->add_observations( groundtruth );
    size_t num_neg_obs = 0;
    size_t possible_neg_obs = 0;
    for( auto cell : grid.all_cells() ) {
      if( (*grid( cell )) == true ) {
      } else {
	if( rand() % 10 == 1) {
	  num_neg_obs++;
	  model->add_negative_observation( grid.region( cell ) );
	}
	++possible_neg_obs;
      }
    }
    std::cout << "num negative observations: " << num_neg_obs << " / " << possible_neg_obs << std::endl;
    model->mcmc( 10 );

    // create the name of the intensity image
    std::ostringstream oss;
    oss << "intensity-" << model_id << ".png";
    std::cout << "  ... creating intensity estimate  ..." << std::endl;
    histogram_t<double> intensity_estimate = model->intensity_estimate( window,
									200,
									100);
    
    save_png( oss.str(), intensity_estimate );
    std::cout << "created intensity estimate: " << oss.str() << std::endl;

  }
  
}
