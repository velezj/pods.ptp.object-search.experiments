
#include "models.hpp"
#include <ruler-point-process/ruler_point_process.hpp>

using namespace point_process_core;
using namespace ruler_point_process;
using namespace math_core;

namespace rawseeds_experiments { namespace models {

    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_small_001( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = zero_point( dim );
      model.prior_ruler_direction_mean = zero_point( dim );
      model.alpha = 1;
      model.precision_distribution.shape = 500000;
      model.precision_distribution.rate = 1000;
      model.period_distribution.p = pow(2.15,40);
      model.period_distribution.q = 2.15*40;
      model.period_distribution.r = 40;
      model.period_distribution.s = 40;
      model.ruler_length_distribution.p = pow(10,40);
      model.ruler_length_distribution.q = 10 * 40;
      model.ruler_length_distribution.r = 40;
      model.ruler_length_distribution.s = 40;
      model.ruler_start_mean_distribution.dimension = dim;
      model.ruler_start_mean_distribution.means.push_back( 0.4 );
      model.ruler_start_mean_distribution.means.push_back( 0.4 );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (0.4*0.4) );
      model.ruler_start_precision_distribution.shape = 5000;
      model.ruler_start_precision_distribution.rate = 100;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( 10 );
      model.ruler_direction_mean_distribution.means.push_back( 10 );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1 );
      model.ruler_direction_precision_distribution.shape = 5000;
      model.ruler_direction_precision_distribution.rate = 100;
      std::vector<nd_point_t> init_points;
      init_points.push_back( point( 0.0, 0.0 ) );
      init_points.push_back( point( 1.0, 1.0 ) );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }

    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_small_002( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = zero_point( dim );
      model.prior_ruler_direction_mean = zero_point( dim );
      model.alpha = 1;
      model.precision_distribution.shape = 500;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow(2.15,4);
      model.period_distribution.q = 2.15*4;
      model.period_distribution.r = 4;
      model.period_distribution.s = 4;
      model.ruler_length_distribution.p = pow(10,4);
      model.ruler_length_distribution.q = 10 * 4;
      model.ruler_length_distribution.r = 4;
      model.ruler_length_distribution.s = 4;
      model.ruler_start_mean_distribution.dimension = dim;
      model.ruler_start_mean_distribution.means.push_back( 0.4 );
      model.ruler_start_mean_distribution.means.push_back( 0.4 );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (0.4*0.4) );
      model.ruler_start_precision_distribution.shape = 500;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( 10 );
      model.ruler_direction_mean_distribution.means.push_back( 10 );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( point( 0.0, 0.0 ) );
      init_points.push_back( point( 1.0, 1.0 ) );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }

    
    //=====================================================================
    

  }
}
