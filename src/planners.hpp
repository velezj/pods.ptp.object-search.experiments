
#if !defined( __P2L_RAWSEEDS_EXPERIMENTS_planners_HPP__ )
#define __P2L_RAWSEEDS_EXPERIMENTS_planners_HPP__

#include <point-process-experiment-core/experiment_utils.hpp>

namespace rawseeds_experiments { namespace planners {


    //=====================================================================
    
    // Descripion:
    // A standard shortest_net_path planner
    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_001
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================

    // Descripion:
    // A debug shortest_next_path planner
    boost::shared_ptr<planner_core::grid_planner_t>
    debug_shortest_path_next_planner_001
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================
    
    // Descripion:
    // A standard shortest_net_path planner
    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_001_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    
    //=====================================================================

    // Descripion:
    // A debug shortest_next_path planner
    boost::shared_ptr<planner_core::grid_planner_t>
    debug_shortest_path_next_planner_001_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================

    // Descripion:
    // A coverage planner
    boost::shared_ptr<planner_core::grid_planner_t>
    coverage_planner_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================

    // Descripion:
    // A coverage planner
    boost::shared_ptr<planner_core::grid_planner_t>
    coverage_planner_1grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);


    //=====================================================================

    // Descripion:
    // A coverage planner
    boost::shared_ptr<planner_core::grid_planner_t>
    coverage_planner_200grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================

    // Descripion:
    // A coverage planner
    boost::shared_ptr<planner_core::grid_planner_t>
    coverage_planner_1e3grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================
    
    // Descripion:
    // A standard shortest_next_path planner
    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_002
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================
    
    // Descripion:
    // A standard shortest_next_path planner
    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_002_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================
    
    // Descripion:
    // A standard shortest_next_path planner
    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_002_1e3grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);


    //=====================================================================
    
    // Descripion:
    // A standard shortest_next_path planner
    boost::shared_ptr<planner_core::grid_planner_t>
    shortest_path_next_planner_003_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================
    
    // Descripion:
    // A standard one_action_entropy_reduction planner
    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_001_1grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);


    //=====================================================================
    
    // Descripion:
    // A standard one_action_entropy_reduction planner
    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_001_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================
    
    // Descripion:
    // A standard one_action_entropy_reduction planner
    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_002_1grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);


    //=====================================================================
    
    // Descripion:
    // A standard one_action_entropy_reduction planner
    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_002_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================
    
    // Descripion:
    // A standard one_action_entropy_reduction planner
    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_002_200grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);


    //=====================================================================
    
    // Descripion:
    // A standard one_action_entropy_reduction planner
    boost::shared_ptr<planner_core::grid_planner_t>
    one_action_entropy_reduction_planner_002_1e3grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);

    //=====================================================================
    
    // Descripion:
    // A standard random planners
    boost::shared_ptr<planner_core::grid_planner_t>
    random_planner_10grid
    (boost::shared_ptr<point_process_core::mcmc_point_process_t>& model);


  }
}

#endif

