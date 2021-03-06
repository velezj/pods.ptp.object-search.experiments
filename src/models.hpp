
#if !defined( __P2L_RAWSEEDS_EXPERIMENTS_models_HPP__ )
#define __P2L_RAWSEEDS_EXPERIMENTS_models_HPP__

#include <point-process-experiment-core/experiment_utils.hpp>

namespace rawseeds_experiments { namespace models {

    
    //======================================================================

    // Description:
    // A ruler-point-process model with strong priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_small_001( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt );

    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_small_002( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    
    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_small_002( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    
    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mode_small_002( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_small_003( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_small_003( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    
    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mode_small_003( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_004( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_004( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    
    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mode_004( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );


    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_005( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_005( const math_core::nd_aabox_t& window ,
		       const std::vector< math_core::nd_point_t >& gt );

    
    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mode_005( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    
    //======================================================================
    
    // Description:
    // An igmm-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    igmm_2d_weak_001( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_006( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );
    
    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_007( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );
    
    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_008( const math_core::nd_aabox_t& window,
			const std::vector< math_core::nd_point_t >& gt  );

    
    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    ruler_2d_mean_lengthprior_008
    ( const math_core::nd_aabox_t& window,
      const std::vector< math_core::nd_point_t >& gt  );

    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors for birds data
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    birds_mean_001( const math_core::nd_aabox_t& window,
		    const std::vector< math_core::nd_point_t >& gt  );


    //======================================================================

    // Description:
    // A ruler-point-process model with weak priors for birds data
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    birds_mean_002a( const math_core::nd_aabox_t& window,
		     const std::vector< math_core::nd_point_t >& gt  );
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    birds_mean_002b( const math_core::nd_aabox_t& window,
		     const std::vector< math_core::nd_point_t >& gt  );



    //======================================================================

    // Description:
    // A igmm-point-process model with weak priors for birds data
    boost::shared_ptr<point_process_core::mcmc_point_process_t>
    birds_igmm_001( const math_core::nd_aabox_t& window,
		    const std::vector< math_core::nd_point_t >& gt  );

    
    //======================================================================

    
  }
}

#endif
