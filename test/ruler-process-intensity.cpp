
#include <p2l-rawseeds-experiments/register.hpp>
#include <point-process-experiment-core/experiment_utils.hpp>
#include <point-process-experiment-core/experiment_runner.hpp>
#include <probability-core/distribution_utils.hpp>
#include <math-core/io.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>


using namespace math_core;
using namespace point_process_experiment_core;
using namespace point_process_core;
using namespace probability_core;


void save_ssv( const std::string& filename,
	       const marked_grid_t<double>& g )
{

  std::ofstream fout( filename.c_str() );
  std::vector<marked_grid_cell_t> cells = g.all_cells_ordered();
  for( marked_grid_cell_t cell : cells ) {
    nd_aabox_t region = g.region( cell );
    nd_point_t center = centroid( region );
    double value = 0;
    if( g( cell ) ) {
      value = *g(cell);
    }
    fout << cell.coordinate[0] << " "
	 << cell.coordinate[1] << " "
	 << center.coordinate[0] << " "
	 << center.coordinate[1] << " "
	 << length(region,0) << " "
	 << length(region,1) << " "
	 << value << std::endl;
  }

}

int main( int argc, char** argv )
{
  
  rawseeds_experiments::rawseeds_registration_type::register_experiments();


  // get the world to test
  //std::string data_id = "rawseeds::small_001";
  //std::string data_id = "rawseeds::biccoca_2009_02_27a";
  std::string data_id = "birds::fred_2003";
  std::vector<nd_point_t> groundtruth = groundtruth_for_world( data_id );
  nd_aabox_t window = window_for_world( data_id );

  std::cout << "data: " << data_id << "   " << groundtruth.size() << " points in " << window << std::endl;


  std::vector<std::string> models{ 
    //"rawseeds::igmm_2d_weak_001",
      // "rawseeds::ruler_2d_mean_006",
      // "rawseeds::ruler_2d_mean_007",
      "rawseeds::ruler_2d_mean_008",
      };
  
  // test all known models
  for( auto model_id : models ) {

    std::cout << "testing model: " << model_id << std::endl;

    // get the mode to test
    boost::shared_ptr<mcmc_point_process_t> model = get_model_by_id( model_id, window, groundtruth );

    // ok, now add some observations to the model,
    // all of the ground truth and some empty regions
    bool add_data = true;
    if( add_data ) {
      double model_res = 1000.0;
      marked_grid_t<bool> grid = point_set_as_grid( groundtruth, window, model_res );
      std::cout << "marked cells: " << grid.all_marked_cells().size() << " / " << grid.all_cells().size() << std::endl;
      model->add_observations( groundtruth );
      size_t num_neg_obs = 0;
      size_t possible_neg_obs = 0;
      double neg_p = 1.0;
      for( auto cell : grid.all_cells() ) {
	if( grid(cell) &&
	    *grid(cell) == true ) {
	} else {
	  if( flip_coin( neg_p ) ) {
	    num_neg_obs++;
	    model->add_negative_observation( grid.region( cell ) );
	  }
	  ++possible_neg_obs;
	}
      }
      std::cout << "num negative observations: " << num_neg_obs << " / " << possible_neg_obs << std::endl;
      //model->mcmc( 10 );
    }

    // compute the bins to each be a certain meters across
    double meters_per_bin = 100.0;
    size_t bins_for_intensity = (int)( ( window.end.coordinate[0] - window.start.coordinate[1] ) / meters_per_bin );

    // create the name of the intensity image
    std::ostringstream oss;
    oss << "intensity-10-" << add_data << "-" << model_id << ".bmp";
    std::cout << "  ... creating intensity estimate  ..." << std::endl;
    size_t intensity_samples = 1000;
    size_t skip_samples = 10;
    histogram_t<double> intensity_estimate = model->intensity_estimate( window,
									bins_for_intensity,
									intensity_samples,
									skip_samples,
									true);
    
    save_bmp( oss.str(), intensity_estimate );
    oss << ".ssv";
    save_ssv( oss.str(), intensity_estimate );
    std::cout << "created intensity estimate: " << oss.str() << std::endl;

  }
  
}
