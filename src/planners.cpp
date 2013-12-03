
#include "planners.hpp"
#include <planner-core/shortest_path_next_planner.hpp>

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

    

  }
}
