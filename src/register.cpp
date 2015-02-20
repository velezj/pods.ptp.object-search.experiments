
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
      ( "rawseeds::random-subset-0.1::biccoca_2009_02_27a",
	bind( rawseeds_experiments::biccoca_27a_random, 0.1 ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.2::biccoca_2009_02_27a",
	bind( rawseeds_experiments::biccoca_27a_random, 0.2 ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.3::biccoca_2009_02_27a",
	bind( rawseeds_experiments::biccoca_27a_random, 0.3 ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.4::biccoca_2009_02_27a",
	bind( rawseeds_experiments::biccoca_27a_random, 0.4 ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.5::biccoca_2009_02_27a",
	bind( rawseeds_experiments::biccoca_27a_random, 0.5 ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.6::biccoca_2009_02_27a",
	bind( rawseeds_experiments::biccoca_27a_random, 0.6 ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.7::biccoca_2009_02_27a",
	bind( rawseeds_experiments::biccoca_27a_random, 0.7 ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.8::biccoca_2009_02_27a",
	bind( rawseeds_experiments::biccoca_27a_random, 0.8 ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::random-subset-0.9::biccoca_2009_02_27a",
	bind( rawseeds_experiments::biccoca_27a_random, 0.9 ),
	bind( rawseeds_experiments::window_for_world, "biccoca_2009_02_27a" ) );
    register_world
      ( "rawseeds::small_001",
	bind( rawseeds_experiments::groundtruth_for_world, "small_001" ),
	bind( rawseeds_experiments::window_for_world, "small_001" ) );
    register_world
      ( "birds::fred_2003",
	bind( rawseeds_experiments::fred_2003_random, 1.0 ),
	bind( rawseeds_experiments::window_for_world, "birds::fred_2003" ) );
    register_world
      ( "birds::random-subset-0.1::fred_2003",
	bind( rawseeds_experiments::fred_2003_random, 0.1 ),
	bind( rawseeds_experiments::window_for_world, "birds::fred_2003" ) );
    register_world
      ( "birds::WISP::fred_2003",
	bind( rawseeds_experiments::fred_2003_species_random, "WISP", 1.0 ),
	bind( rawseeds_experiments::window_for_world, "birds::fred_2003" ) );
    register_world
      ( "birds::SOFU::fred_2003",
	bind( rawseeds_experiments::fred_2003_species_random, "SOFU", 1.0 ),
	bind( rawseeds_experiments::window_for_world, "birds::fred_2003" ) );
    register_world
      ( "random_001::200",
	bind( rawseeds_experiments::random_world_001, 200 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::2000",
	bind( rawseeds_experiments::random_world_001, 2000 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::10",
	bind( rawseeds_experiments::random_world_001, 10 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::20",
	bind( rawseeds_experiments::random_world_001, 20 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::30",
	bind( rawseeds_experiments::random_world_001, 30 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::40",
	bind( rawseeds_experiments::random_world_001, 40 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::50",
	bind( rawseeds_experiments::random_world_001, 50 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::60",
	bind( rawseeds_experiments::random_world_001, 60 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::70",
	bind( rawseeds_experiments::random_world_001, 70 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::80",
	bind( rawseeds_experiments::random_world_001, 80 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::90",
	bind( rawseeds_experiments::random_world_001, 90 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::100",
	bind( rawseeds_experiments::random_world_001, 100 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::1000",
	bind( rawseeds_experiments::random_world_001, 1000 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );
    register_world
      ( "random_001::10000",
	bind( rawseeds_experiments::random_world_001, 10000 ),
	bind( rawseeds_experiments::window_for_world, "random_001" ) );



    

    // register all models
    boost::function< boost::shared_ptr<point_process_core::mcmc_point_process_t> (const math_core::nd_aabox_t&,const std::vector<math_core::nd_point_t>& gt )> model_f;
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
    model_f = rawseeds_experiments::models::ruler_2d_mean_006;
    register_model
      ( "rawseeds::ruler_2d_mean_006",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mean_007;
    register_model
      ( "rawseeds::ruler_2d_mean_007",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mean_008;
    register_model
      ( "rawseeds::ruler_2d_mean_008",
	model_f);
    model_f = rawseeds_experiments::models::ruler_2d_mean_lengthprior_008;
    register_model
      ( "rawseeds::ruler_2d_mean_lengthprior_008",
	model_f);
    model_f = rawseeds_experiments::models::birds_mean_001;
    register_model
      ( "birds::birds_mean_001",
	model_f);
    model_f = rawseeds_experiments::models::birds_mean_002a;
    register_model
      ( "birds::birds_mean_002a",
	model_f);
    model_f = rawseeds_experiments::models::birds_mean_002b;
    register_model
      ( "birds::birds_mean_002b",
	model_f);
    model_f = rawseeds_experiments::models::birds_igmm_001;
    register_model
      ( "birds::birds_igmm_001",
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
    planner_f = rawseeds_experiments::planners::coverage_planner_200grid;
    register_planner
      ( "rawseeds::coverage_planner_200grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::coverage_planner_1e3grid;
    register_planner
      ( "rawseeds::coverage_planner_1e3grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::shortest_path_next_planner_002;
    register_planner
      ( "rawseeds::shortest_path_next_planner_002",
	planner_f);
    planner_f = rawseeds_experiments::planners::shortest_path_next_planner_002_10grid;
    register_planner
      ( "rawseeds::shortest_path_next_planner_002_10grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::shortest_path_next_planner_002_1e3grid;
    register_planner
      ( "rawseeds::shortest_path_next_planner_002_1e3grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::shortest_path_next_planner_003_10grid;
    register_planner
      ( "rawseeds::shortest_path_next_planner_003_10grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::one_action_entropy_reduction_planner_001_1grid;
    register_planner
      ( "rawseeds::one_action_entropy_reduction_planner_001_1grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::one_action_entropy_reduction_planner_001_10grid;
    register_planner
      ( "rawseeds::one_action_entropy_reduction_planner_001_10grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::one_action_entropy_reduction_planner_002_1grid;
    register_planner
      ( "rawseeds::one_action_entropy_reduction_planner_002_1grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::one_action_entropy_reduction_planner_002_10grid;
    register_planner
      ( "rawseeds::one_action_entropy_reduction_planner_002_10grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::one_action_entropy_reduction_planner_002_200grid;
    register_planner
      ( "rawseeds::one_action_entropy_reduction_planner_002_200grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::one_action_entropy_reduction_planner_002_1e3grid;
    register_planner
      ( "rawseeds::one_action_entropy_reduction_planner_002_1e3grid",
	planner_f);
    planner_f = rawseeds_experiments::planners::random_planner_10grid;
    register_planner
      ( "rawseeds::random_planner_10grid",
	planner_f);

  }

  //=========================================================================
  //=========================================================================
  //=========================================================================
  //=========================================================================
  //=========================================================================

}
