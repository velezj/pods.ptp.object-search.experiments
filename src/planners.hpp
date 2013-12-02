
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


  }
}

#endif

