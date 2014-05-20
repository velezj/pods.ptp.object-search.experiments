
#include "planners.hpp"
#include <planner-core/shortest_path_next_planner.hpp>
#include <planner-core/coverage_planner.hpp>
#include <planner-core/one_action_entropy_reduction_planner.hpp>

using namespace planner_core;

namespace rawseeds_experiments { namespace planners {


    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_001
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 50;
      planner_params.update_model_mcmc_iterations = 50;
      planner_params.grid_cell_size = 1.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 10;
      sampler_planner_params.num_samples_of_point_sets = 100;
      sampler_planner_params.num_skip_between_point_set_samples = 10;
      double prob_thresh = 0.6;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new shortest_path_next_planner ( model,
					  planner_params,
					  entropy_params,
					  sampler_planner_params,
					  prob_thresh)
	 );
    
      return planner;
    }


    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    debug_shortest_path_next_planner_001
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 1;
      planner_params.update_model_mcmc_iterations = 1;
      planner_params.grid_cell_size = 1.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 2;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 1;
      sampler_planner_params.num_samples_of_point_sets = 2;
      sampler_planner_params.num_skip_between_point_set_samples = 0;
      double prob_thresh = 0.6;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new shortest_path_next_planner ( model,
					  planner_params,
					  entropy_params,
					  sampler_planner_params,
					  prob_thresh)
	 );
    
      return planner;

    }


    //=====================================================================

    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_001_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 50;
      planner_params.update_model_mcmc_iterations = 50;
      planner_params.grid_cell_size = 10.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 10;
      sampler_planner_params.num_samples_of_point_sets = 100;
      sampler_planner_params.num_skip_between_point_set_samples = 10;
      double prob_thresh = 0.6;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new shortest_path_next_planner ( model,
					  planner_params,
					  entropy_params,
					  sampler_planner_params,
					  prob_thresh)
	 );
    
      return planner;
    }




    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    debug_shortest_path_next_planner_001_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 1;
      planner_params.update_model_mcmc_iterations = 1;
      planner_params.grid_cell_size = 10.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 2;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 1;
      sampler_planner_params.num_samples_of_point_sets = 2;
      sampler_planner_params.num_skip_between_point_set_samples = 0;
      double prob_thresh = 0.6;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new shortest_path_next_planner ( model,
					  planner_params,
					  entropy_params,
					  sampler_planner_params,
					  prob_thresh)
	 );
    
      return planner;

    }

    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    coverage_planner_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 1;
      planner_params.update_model_mcmc_iterations = 1;
      planner_params.grid_cell_size = 10.0;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new coverage_planner ( model,
				planner_params )
	 );
      
      return planner;
      
    }

    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    coverage_planner_1grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 1;
      planner_params.update_model_mcmc_iterations = 1;
      planner_params.grid_cell_size = 1.0;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new coverage_planner ( model,
				planner_params )
	 );
      
      return planner;
      
    }

    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    coverage_planner_200grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 1;
      planner_params.update_model_mcmc_iterations = 1;
      planner_params.grid_cell_size = 200.0;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new coverage_planner ( model,
				planner_params )
	 );
      
      return planner;
      
    }


    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    coverage_planner_1e3grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 1;
      planner_params.update_model_mcmc_iterations = 1;
      planner_params.grid_cell_size = 1e3;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new coverage_planner ( model,
				planner_params )
	 );
      
      return planner;
      
    }


    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_002
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 10;
      planner_params.update_model_mcmc_iterations = 2;
      planner_params.grid_cell_size = 1.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 10;
      sampler_planner_params.num_samples_of_point_sets = 20;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      double prob_thresh = 0.6;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new shortest_path_next_planner ( model,
					  planner_params,
					  entropy_params,
					  sampler_planner_params,
					  prob_thresh)
	 );
    
      return planner;
    }

    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_002_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 10;
      planner_params.update_model_mcmc_iterations = 2;
      planner_params.grid_cell_size = 10.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 10;
      sampler_planner_params.num_samples_of_point_sets = 20;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      double prob_thresh = 0.6;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new shortest_path_next_planner ( model,
					  planner_params,
					  entropy_params,
					  sampler_planner_params,
					  prob_thresh)
	 );
    
      return planner;
    }

    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_002_1e3grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 10;
      planner_params.update_model_mcmc_iterations = 2;
      planner_params.grid_cell_size = 1e3;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 10;
      sampler_planner_params.num_samples_of_point_sets = 20;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      double prob_thresh = 0.6;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new shortest_path_next_planner ( model,
					  planner_params,
					  entropy_params,
					  sampler_planner_params,
					  prob_thresh)
	 );
    
      return planner;
    }



    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_003_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 100;
      planner_params.update_model_mcmc_iterations = 30;
      planner_params.grid_cell_size = 10.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 10;
      sampler_planner_params.num_samples_of_point_sets = 2;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      double prob_thresh = 0.6;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new shortest_path_next_planner ( model,
					  planner_params,
					  entropy_params,
					  sampler_planner_params,
					  prob_thresh)
	 );
    
      return planner;
    }


    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_001_1grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 1;
      planner_params.update_model_mcmc_iterations = 1;
      planner_params.grid_cell_size = 1.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 1;
      sampler_planner_params.num_samples_of_point_sets = 1;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new one_action_entropy_reduction_planner_t ( model,
						      planner_params,
						      entropy_params,
						      sampler_planner_params)
	 );
    
      return planner;
    }



    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_001_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 1;
      planner_params.update_model_mcmc_iterations = 1;
      planner_params.grid_cell_size = 10.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 1;
      sampler_planner_params.num_samples_of_point_sets = 1;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new one_action_entropy_reduction_planner_t ( model,
						      planner_params,
						      entropy_params,
						      sampler_planner_params)
	 );
    
      return planner;
    }


    //=====================================================================


    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_002_1grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 100;
      planner_params.update_model_mcmc_iterations = 10;
      planner_params.grid_cell_size = 1.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 1;
      sampler_planner_params.num_samples_of_point_sets = 10;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new one_action_entropy_reduction_planner_t ( model,
						      planner_params,
						      entropy_params,
						      sampler_planner_params)
	 );
    
      return planner;
    }



    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_002_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 100;
      planner_params.update_model_mcmc_iterations = 10;
      planner_params.grid_cell_size = 10.0;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 1;
      sampler_planner_params.num_samples_of_point_sets = 10;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new one_action_entropy_reduction_planner_t ( model,
						      planner_params,
						      entropy_params,
						      sampler_planner_params)
	 );
    
      return planner;
    }

    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_002_200grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 100;
      planner_params.update_model_mcmc_iterations = 10;
      planner_params.grid_cell_size = 200;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 1;
      sampler_planner_params.num_samples_of_point_sets = 10;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new one_action_entropy_reduction_planner_t ( model,
						      planner_params,
						      entropy_params,
						      sampler_planner_params)
	 );
    
      return planner;
    }



    //=====================================================================

    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_002_1e3grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model)
    {
      grid_planner_parameters_t planner_params;
      planner_params.burnin_mcmc_iterations = 100;
      planner_params.update_model_mcmc_iterations = 10;
      planner_params.grid_cell_size = 1e3;
      entropy_estimator_parameters_t entropy_params;
      entropy_params.num_samples = 10;
      sampler_planner_parameters_t sampler_planner_params;
      sampler_planner_params.num_samples_of_observations = 1;
      sampler_planner_params.num_samples_of_point_sets = 10;
      sampler_planner_params.num_skip_between_point_set_samples = 1;
      boost::shared_ptr<grid_planner_t> planner
	= boost::shared_ptr<grid_planner_t>
	(
	 new one_action_entropy_reduction_planner_t ( model,
						      planner_params,
						      entropy_params,
						      sampler_planner_params)
	 );
    
      return planner;
    }



    //=====================================================================

    

  }
}
