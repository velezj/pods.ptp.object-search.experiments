
#include "data_loader.hpp"
#include <point-process-experiment-core/data_io.hpp>
#include <fstream>


using namespace math_core;
using namespace point_process_experiment_core;


namespace rawseeds_experiments {


  //============================================================================
  
  std::vector<nd_point_t>
  groundtruth_for_world( const std::string& world )
  {
    // handle unknwon worlds
    if( world != "biccoca_2009_02_27a" ) {
      BOOST_THROW_EXCEPTION( unknown_rawseeds_world_exception() );
    }
    
    // ok, look up the centroid file SSV and parse it
    std::ifstream fin( "/home/velezj/projects/gits/p2l-system/build/bin/data/bicocca-2009-02-27a/labeled-signs-1-centroids.ssv" );
    std::vector<nd_point_t> points = parse_points_from_ssv_stream( fin );
    fin.close();
    return points;
  }
  
  //============================================================================
  
  nd_aabox_t window_for_world( const std::string& world )
  {
    // handle unknwon worlds
    if( world != "biccoca_2009_02_27a" ) {
      BOOST_THROW_EXCEPTION( unknown_rawseeds_world_exception() );
    }
    
    return aabox( point( 0.0, -40.0 ), point( 160.0, 40.0 ) );
  }
  
  //============================================================================
  //============================================================================
  //============================================================================
  //============================================================================
  //============================================================================
  //============================================================================
  //============================================================================
  //============================================================================
  //============================================================================
  //============================================================================
  
}
