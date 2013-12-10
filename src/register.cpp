
#include "register.hpp"
#include "models.hpp"
#include "planners.hpp"
#include "data_loader.hpp"
#include <point-process-experiment-core/experiment_utils.hpp>
#include <boost/bind.hpp>


namespace rawseeds_experiments {

  //=========================================================================

  void rawseeds_registration_type::register_experiments() {

    using namespace point_process_experiment_core;
    using namespace boost;


    // register all the worlds
    register_world
      ( "rawseeds::biccoca_2009_02_27a",
	bind( rawseeds_experiments::groundtruth_for_world, "biccoca_2009_02_27a" ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.5::biccoca_2009_02_27a",
	bind( rawseeds_experiments::groundtruth_for_world, "random-subset-0.5::biccoca_2009_02_27a" ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.1::biccoca_2009_02_27a",
	bind( rawseeds_experiments::groundtruth_for_world, "random-subset-0.1::biccoca_2009_02_27a" ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.3::biccoca_2009_02_27a",
	bind( rawseeds_experiments::groundtruth_for_world, "random-subset-0.3::biccoca_2009_02_27a" ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::small_001",
	bind( rawseeds_experiments::groundtruth_for_world, "small_001" ),
	bind( rawseeds_experiments::window_for_world, "small_001" ) );
    

    // register all models
    boost::function< boost::shared_ptr<point_process_core::mcmc_point_process_t> (const math_core::nd_aabox_t&)> model_f;
    model_f = rawseeds_experiments::models::ruler_2d_small_001;
    register_model
      ( "rawseeds::ruler_2d_small_001",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_small_002;
    register_model
      ( "rawseeds::ruler_2d_small_002",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mean_small_002;
    register_model
      ( "rawseeds::ruler_2d_mean_small_002",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mode_small_002;
    register_model
      ( "rawseeds::ruler_2d_mode_small_002",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_small_003;
    register_model
      ( "rawseeds::ruler_2d_small_003",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mean_small_003;
    register_model
      ( "rawseeds::ruler_2d_mean_small_003",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mode_small_003;
    register_model
      ( "rawseeds::ruler_2d_mode_small_003",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_004;
    register_model
      ( "rawseeds::ruler_2d_004",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mean_004;
    register_model
      ( "rawseeds::ruler_2d_mean_004",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mode_004;
    register_model
      ( "rawseeds::ruler_2d_mode_004",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_005;
    register_model
      ( "rawseeds::ruler_2d_005",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mean_005;
    register_model
      ( "rawseeds::ruler_2d_mean_005",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mode_005;
    register_model
      ( "rawseeds::ruler_2d_mode_005",
	model_f);
    model_f = rawseeds_experiments::models::igmm_2d_weak_001;
    register_model
      ( "rawseeds::igmm_2d_weak_001",
	model_f);


    
    // register all planners
    boost::function< boost::shared_ptr<planner_core::grid_planner_t> ( boost::shared_ptr<point_process_core::mcmc_point_process_t>&) > planner_f;
    planner_f = rawseeds_experiments::planners::shortest_path_next_planner_001;
    register_planner
      ( "rawseeds::shortest_path_next_planner_001",
	planner_f);
    planner_f = rawseeds_experiments::planners::debug_shortest_path_next_planner_001;
    register_planner
      ( "rawseeds::debug::shortest_path_next_planner_001",
	planner_f);
    planner_f = rawseeds_experiments::planners::shortest_path_next_planner_001_10grid;
    register_planner
      ( "rawseeds::shortest_path_next_planner_001_10grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::debug_shortest_path_next_planner_001_10grid;
    register_planner
      ( "rawseeds::debug::shortest_path_next_planner_001_10grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::coverage_planner_10grid;
    register_planner
      ( "rawseeds::coverage_planner_10grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::coverage_planner_1grid;
    register_planner
      ( "rawseeds::coverage_planner",
	planner_f);
    planner_f = rawseeds_experiments::planners::shortest_path_next_planner_002;
    register_planner
      ( "rawseeds::shortest_path_next_planner_002",
	planner_f);
    planner_f = rawseeds_experiments::planners::shortest_path_next_planner_002_10grid;
    register_planner
      ( "rawseeds::shortest_path_next_planner_002_10grid",
	planner_f);
  }

  //=========================================================================
  //=========================================================================
  //=========================================================================
  //=========================================================================
  //=========================================================================

}
