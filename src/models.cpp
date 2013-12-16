
#include "models.hpp"
#include <ruler-point-process/ruler_point_process.hpp>
#include <igmm-point-process/igmm_point_process.hpp>

using namespace point_process_core;
using namespace ruler_point_process;
using namespace igmm_point_process;
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

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_small_002( const math_core::nd_aabox_t& window )
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
      process->set_liklihood_algorithm( mean_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }
    
    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mode_small_002( const math_core::nd_aabox_t& window )
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
      process->set_liklihood_algorithm( mode_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }

    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_small_003( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      std::vector<double> two_unit, unit;
      for( size_t i = 0; i < dim; ++i ) {
	unit.push_back( 1.0 );
	two_unit.push_back( 2.0 );
      }
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = point( two_unit );
      model.prior_ruler_direction_mean = point( unit );
      model.alpha = 1;
      model.precision_distribution.shape = 50;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow(2.15,4);
      model.period_distribution.q = 2.15*4;
      model.period_distribution.r = 4;
      model.period_distribution.s = 4;
      model.ruler_length_distribution.p = pow(12,4);
      model.ruler_length_distribution.q = 12 * 4;
      model.ruler_length_distribution.r = 4;
      model.ruler_length_distribution.s = 4;
      model.ruler_start_mean_distribution.dimension = dim;
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (1.0*1.0) );
      model.ruler_start_precision_distribution.shape = 50;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( 10.0 );
      model.ruler_direction_mean_distribution.means.push_back( 10.0 );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( point( 2.0, 2.0 ) );
      init_points.push_back( point( 4.0, 4.0 ) );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      process->set_liklihood_algorithm( monte_carlo_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }
    
    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_small_003( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      std::vector<double> two_unit, unit;
      for( size_t i = 0; i < dim; ++i ) {
	unit.push_back( 1.0 );
	two_unit.push_back( 2.0 );
      }
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = point( two_unit );
      model.prior_ruler_direction_mean = point( unit );
      model.alpha = 1;
      model.precision_distribution.shape = 50;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow(2.15,4);
      model.period_distribution.q = 2.15*4;
      model.period_distribution.r = 4;
      model.period_distribution.s = 4;
      model.ruler_length_distribution.p = pow(12,4);
      model.ruler_length_distribution.q = 12 * 4;
      model.ruler_length_distribution.r = 4;
      model.ruler_length_distribution.s = 4;
      model.ruler_start_mean_distribution.dimension = dim;
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (1.0*1.0) );
      model.ruler_start_precision_distribution.shape = 50;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( 10.0 );
      model.ruler_direction_mean_distribution.means.push_back( 10.0 );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( point( 2.0, 2.0 ) );
      init_points.push_back( point( 4.0, 4.0 ) );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      process->set_liklihood_algorithm( mean_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }
    
    
    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mode_small_003( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      std::vector<double> two_unit, unit;
      for( size_t i = 0; i < dim; ++i ) {
	unit.push_back( 1.0 );
	two_unit.push_back( 2.0 );
      }
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = point( two_unit );
      model.prior_ruler_direction_mean = point( unit );
      model.alpha = 1;
      model.precision_distribution.shape = 50;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow(2.15,4);
      model.period_distribution.q = 2.15*4;
      model.period_distribution.r = 4;
      model.period_distribution.s = 4;
      model.ruler_length_distribution.p = pow(12,4);
      model.ruler_length_distribution.q = 12 * 4;
      model.ruler_length_distribution.r = 4;
      model.ruler_length_distribution.s = 4;
      model.ruler_start_mean_distribution.dimension = dim;
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (1.0*1.0) );
      model.ruler_start_precision_distribution.shape = 50;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( 10.0 );
      model.ruler_direction_mean_distribution.means.push_back( 10.0 );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( point( 2.0, 2.0 ) );
      init_points.push_back( point( 4.0, 4.0 ) );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      process->set_liklihood_algorithm( mode_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }

    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_004( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      std::vector<double> two_unit, unit;
      for( size_t i = 0; i < dim; ++i ) {
	unit.push_back( 1.0 );
	two_unit.push_back( 2.0 );
      }
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = point( two_unit );
      model.prior_ruler_direction_mean = point( unit );
      model.alpha = 1;
      model.precision_distribution.shape = 50;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow(5.0,4);
      model.period_distribution.q = 5.0*4;
      model.period_distribution.r = 4;
      model.period_distribution.s = 4;
      model.ruler_length_distribution.p = pow(100,4);
      model.ruler_length_distribution.q = 100 * 4;
      model.ruler_length_distribution.r = 4;
      model.ruler_length_distribution.s = 4;
      model.ruler_start_mean_distribution.dimension = dim;
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (1.0*1.0) );
      model.ruler_start_precision_distribution.shape = 50;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( 1.0 );
      model.ruler_direction_mean_distribution.means.push_back( 0.0 );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( point( 2.0, 2.0 ) );
      init_points.push_back( point( 4.0, 2.0 ) );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      process->set_liklihood_algorithm( monte_carlo_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }

    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_004( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      std::vector<double> two_unit, unit;
      for( size_t i = 0; i < dim; ++i ) {
	unit.push_back( 1.0 );
	two_unit.push_back( 2.0 );
      }
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = point( two_unit );
      model.prior_ruler_direction_mean = point( unit );
      model.alpha = 1;
      model.precision_distribution.shape = 50;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow(5.0,4);
      model.period_distribution.q = 5.0*4;
      model.period_distribution.r = 4;
      model.period_distribution.s = 4;
      model.ruler_length_distribution.p = pow(100,4);
      model.ruler_length_distribution.q = 100 * 4;
      model.ruler_length_distribution.r = 4;
      model.ruler_length_distribution.s = 4;
      model.ruler_start_mean_distribution.dimension = dim;
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (1.0*1.0) );
      model.ruler_start_precision_distribution.shape = 50;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( 1.0 );
      model.ruler_direction_mean_distribution.means.push_back( 0.0 );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( point( 2.0, 2.0 ) );
      init_points.push_back( point( 4.0, 2.0 ) );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      process->set_liklihood_algorithm( mean_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }


    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mode_004( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      std::vector<double> two_unit, unit;
      for( size_t i = 0; i < dim; ++i ) {
	unit.push_back( 1.0 );
	two_unit.push_back( 2.0 );
      }
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = point( two_unit );
      model.prior_ruler_direction_mean = point( unit );
      model.alpha = 1;
      model.precision_distribution.shape = 50;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow(5.0,4);
      model.period_distribution.q = 5.0*4;
      model.period_distribution.r = 4;
      model.period_distribution.s = 4;
      model.ruler_length_distribution.p = pow(100,4);
      model.ruler_length_distribution.q = 100 * 4;
      model.ruler_length_distribution.r = 4;
      model.ruler_length_distribution.s = 4;
      model.ruler_start_mean_distribution.dimension = dim;
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.means.push_back( 3.0 );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (1.0*1.0) );
      model.ruler_start_precision_distribution.shape = 50;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( 1.0 );
      model.ruler_direction_mean_distribution.means.push_back( 0.0 );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( point( 2.0, 2.0 ) );
      init_points.push_back( point( 4.0, 2.0 ) );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      process->set_liklihood_algorithm( mode_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }


    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_005( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      std::vector<double> two_unit, unit;
      for( size_t i = 0; i < dim; ++i ) {
	unit.push_back( 1.0 );
	two_unit.push_back( 2.0 );
      }
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = window.start + 0.25 * ( window.end - window.start );
      model.prior_ruler_direction_mean = window.end;
      model.alpha = 1;
      model.precision_distribution.shape = 50;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow( 0.15 * magnitude(window.end - window.start ) ,2);
      model.period_distribution.q = 0.15 * magnitude(window.end - window.start ) * 2;
      model.period_distribution.r = 2;
      model.period_distribution.s = 2;
      model.ruler_length_distribution.p = pow( 0.5 * magnitude(window.end - window.start ) , 2);
      model.ruler_length_distribution.q = 0.5 * magnitude(window.end - window.start ) * 2;
      model.ruler_length_distribution.r = 2;
      model.ruler_length_distribution.s = 2;
      model.ruler_start_mean_distribution.dimension = dim;
      nd_point_t mp = centroid( window );
      model.ruler_start_mean_distribution.means.push_back( mp.coordinate[0] );
      model.ruler_start_mean_distribution.means.push_back( mp.coordinate[1] );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (1.0*1.0) );
      model.ruler_start_precision_distribution.shape = 50;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( window.end.coordinate[0] );
      model.ruler_direction_mean_distribution.means.push_back( window.end.coordinate[1] );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( window.start );
      init_points.push_back( window.end );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      process->set_liklihood_algorithm( monte_carlo_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }

        //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_005( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      std::vector<double> two_unit, unit;
      for( size_t i = 0; i < dim; ++i ) {
	unit.push_back( 1.0 );
	two_unit.push_back( 2.0 );
      }
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = window.start + 0.25 * ( window.end - window.start );
      model.prior_ruler_direction_mean = window.end;
      model.alpha = 1;
      model.precision_distribution.shape = 50;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow( 0.15 * magnitude(window.end - window.start ) ,2);
      model.period_distribution.q = 0.15 * magnitude(window.end - window.start ) * 2;
      model.period_distribution.r = 2;
      model.period_distribution.s = 2;
      model.ruler_length_distribution.p = pow( 0.5 * magnitude(window.end - window.start ) , 2);
      model.ruler_length_distribution.q = 0.5 * magnitude(window.end - window.start ) * 2;
      model.ruler_length_distribution.r = 2;
      model.ruler_length_distribution.s = 2;
      model.ruler_start_mean_distribution.dimension = dim;
      nd_point_t mp = centroid( window );
      model.ruler_start_mean_distribution.means.push_back( mp.coordinate[0] );
      model.ruler_start_mean_distribution.means.push_back( mp.coordinate[1] );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (1.0*1.0) );
      model.ruler_start_precision_distribution.shape = 50;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( window.end.coordinate[0] );
      model.ruler_direction_mean_distribution.means.push_back( window.end.coordinate[1] );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( window.start );
      init_points.push_back( window.end );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      process->set_liklihood_algorithm( mean_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }

    //=====================================================================

    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mode_005( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      std::vector<double> two_unit, unit;
      for( size_t i = 0; i < dim; ++i ) {
	unit.push_back( 1.0 );
	two_unit.push_back( 2.0 );
      }
      ruler_point_process_model_t model;
      model.prior_ruler_start_mean = window.start + 0.25 * ( window.end - window.start );
      model.prior_ruler_direction_mean = window.end;
      model.alpha = 1;
      model.precision_distribution.shape = 50;
      model.precision_distribution.rate = 10;
      model.period_distribution.p = pow( 0.15 * magnitude(window.end - window.start ) ,2);
      model.period_distribution.q = 0.15 * magnitude(window.end - window.start ) * 2;
      model.period_distribution.r = 2;
      model.period_distribution.s = 2;
      model.ruler_length_distribution.p = pow( 0.5 * magnitude(window.end - window.start ) , 2);
      model.ruler_length_distribution.q = 0.5 * magnitude(window.end - window.start ) * 2;
      model.ruler_length_distribution.r = 2;
      model.ruler_length_distribution.s = 2;
      model.ruler_start_mean_distribution.dimension = dim;
      nd_point_t mp = centroid( window );
      model.ruler_start_mean_distribution.means.push_back( mp.coordinate[0] );
      model.ruler_start_mean_distribution.means.push_back( mp.coordinate[1] );
      model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (1.0*1.0) );
      model.ruler_start_precision_distribution.shape = 50;
      model.ruler_start_precision_distribution.rate = 10;
      model.ruler_direction_mean_distribution.dimension = dim;
      model.ruler_direction_mean_distribution.means.push_back( window.end.coordinate[0] );
      model.ruler_direction_mean_distribution.means.push_back( window.end.coordinate[1] );
      model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.ruler_direction_precision_distribution.shape = 500;
      model.ruler_direction_precision_distribution.rate = 10;
      std::vector<nd_point_t> init_points;
      init_points.push_back( window.start );
      init_points.push_back( window.end );
      boost::shared_ptr<ruler_point_process_t> process = 
	boost::shared_ptr<ruler_point_process_t>
	( new ruler_point_process_t( window,
				     model,
				     init_points ) );
      process->set_liklihood_algorithm( mode_likelihood_approximation );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      
      return planner_process;
    }
    
    //=====================================================================
    
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    igmm_2d_weak_001( const math_core::nd_aabox_t& window )
    {
      int dim = 2;
      igmm_point_process_model_t model;
      model.alpha = 1;
      model.mean_distribution.dimension = dim;
      model.mean_distribution.means = ( window.start + 0.25 * ( window.end - window.start ) ).coordinate;
      model.mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1.0 );
      model.precision_distribution.shape = 2;
      model.precision_distribution.rate = 0.5;
      model.num_points_per_gaussian_distribution.shape = 2;
      model.num_points_per_gaussian_distribution.rate = 0.5;

      std::vector<nd_point_t> init_points;
      init_points.push_back( window.start );
      init_points.push_back( window.end );
      boost::shared_ptr<igmm_point_process_t> process = 
	boost::shared_ptr<igmm_point_process_t>
	( new igmm_point_process_t( window,
				    model,
				    init_points ) );
      boost::shared_ptr<mcmc_point_process_t> planner_process
	= boost::shared_ptr<mcmc_point_process_t>( process );
      return planner_process;
    }

    //=====================================================================

  }
}
