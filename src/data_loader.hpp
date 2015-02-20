
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
  // Returns a random subset from the biccoca_2009_02_27a dataset
  std::vector<math_core::nd_point_t>
  biccoca_27a_random( const double& f );

  // Description:
  // Returns a random subset from the fred_2003 bird dataset
  std::vector<math_core::nd_point_t>
  fred_2003_random( const double& f );

  // Description:
  // Returns a random subset from the fred_2003_<species> bird dataset
  std::vector<math_core::nd_point_t>
  fred_2003_species_random( const std::string& species, const double& f );

  // Description:
  // Returns a random world with the given number of points
  std::vector<math_core::nd_point_t>
  random_world_001( const size_t& n );

  // Description:
  // Returns the window/bounds for a rawseeds world.
  math_core::nd_aabox_t
  window_for_world( const std::string& world );
}


#endif
