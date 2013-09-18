
#if !defined( __P2L_RAWSEEDS_EXPERIMENTS_data_loader_HPP__ )
#define __P2L_RAWSEEDS_EXPERIMENTS_data_loader_HPP__

#include <math-core/geom.hpp>
#include <vector>
#include <stdexcept>
#include <boost/exception/all.hpp>

namespace rawseeds_experiments {

  // Description:
  // Exception indicating that an unknown rawseeds world was
  // asked for
  struct unknown_rawseeds_world_exception : public virtual std::exception,
					    public virtual boost::exception
  {
  };


  // Description:
  // Returns the gourndtruth set of points for a rawseeds world.
  // Currently known worlds are:
  //    biccoca_2009_02_27a
  std::vector<math_core::nd_point_t>
  groundtruth_for_world( const std::string& world );

  // Description:
  // Returns the window/bounds for a rawseeds world.
  // Currently known worlds are:
  //    biccoca_2009_02_27a
  math_core::nd_aabox_t
  window_for_world( const std::string& world );
}


#endif
