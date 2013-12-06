
#include "data_loader.hpp"
#include <point-process-experiment-core/data_io.hpp>
#include <math-core/io.hpp>
#include <fstream>
#include <algorithm>
#include <iostream>


using namespace math_core;
using namespace point_process_experiment_core;


namespace rawseeds_experiments {


  //============================================================================
  
  std::vector<nd_point_t>
  groundtruth_for_world( const std::string& world )
  {

    std::vector<nd_point_t> points;

    if( world == "biccoca_2009_02_27a" ) {
    
      // ok, look up the centroid file SSV and parse it
      std::ifstream fin( "/home/velezj/projects/gits/p2l-system/build/bin/data/bicocca-2009-02-27a/labeled-signs-1-centroids.ssv" );
      points = parse_points_from_ssv_stream( fin );
      fin.close();
      return points;
    }

    
    if( world == "small_001" ) {
      points.push_back( point( 2.25, 2.25 ) );
      points.push_back( point( 4.25, 4.25 ) );
      points.push_back( point( 6.25, 6.25 ) );
      points.push_back( point( 8.25, 8.25 ) );
      points.push_back( point( 2.55, 2.55 ) );
      points.push_back( point( 4.55, 4.55 ) );
      points.push_back( point( 6.55, 6.55 ) );
      points.push_back( point( 8.55, 8.55 ) );
      return points;
    }

    
    if( world == "random-subset-0.5::biccoca_2009_02_27a" ) {
      // ok, look up the centroid file SSV and parse it
      std::ifstream fin( "/home/velezj/projects/gits/p2l-system/build/bin/data/bicocca-2009-02-27a/labeled-signs-1-centroids.ssv" );
      points = parse_points_from_ssv_stream( fin );
      fin.close();
      // randomly shulfffe points and pick first half
      if( points.empty() == false ) {
	std::random_shuffle( points.begin(), points.end() );
	points.erase( points.begin() + (points.size() / 2),
		      points.end() );
      }
      return points;
    }

    if( world == "random-subset-0.3::biccoca_2009_02_27a" ) {
      // ok, look up the centroid file SSV and parse it
      std::ifstream fin( "/home/velezj/projects/gits/p2l-system/build/bin/data/bicocca-2009-02-27a/labeled-signs-1-centroids.ssv" );
      points = parse_points_from_ssv_stream( fin );
      fin.close();
      // randomly shulfffe points and pick first half
      if( points.size() >= int(10 / 3.0) ) {
	std::random_shuffle( points.begin(), points.end() );
	points.erase( points.begin() + int(3.0 * points.size() / 10),
		      points.end() );
      }
      return points;
    }



    if( world == "random-subset-0.1::biccoca_2009_02_27a" ) {
      // ok, look up the centroid file SSV and parse it
      std::ifstream fin( "/home/velezj/projects/gits/p2l-system/build/bin/data/bicocca-2009-02-27a/labeled-signs-1-centroids.ssv" );
      points = parse_points_from_ssv_stream( fin );
      fin.close();

      // simply find max start and min end points for the cell regions
      nd_point_t max_point = points[0];
      nd_point_t min_point = points[0];
      for( size_t i = 1; i < points.size(); ++i ) {
	nd_point_t s = points[i];
	
	// update max/min points
	if( point_lexicographical_compare( max_point, s ) ) {
	  max_point = s;
	}
	if( point_lexicographical_compare( s, min_point ) ) {
	  min_point = s;
	}
      }
      std::cout << "  Full *actual* rawseeds window: " << aabox( min_point, max_point ) << std::endl;
      
      
      // randomly shulfffe points and pick first half
      if( points.size() >= 10 ) {
	std::random_shuffle( points.begin(), points.end() );
	points.erase( points.begin() + (points.size() / 10),
		      points.end() );
      }
      return points;
    }
    

    // if we got here., unknown world
    BOOST_THROW_EXCEPTION( unknown_rawseeds_world_exception() );
  }
  
  //============================================================================
  
  nd_aabox_t window_for_world( const std::string& world )
  {

    if( world == "biccoca_2009_02_27a" ) {
      return aabox( point( -20.0, -40.0 ), point( 160.0, 40.0 ) );
    }

    if( world == "small_001" ) {
      return aabox( point( 0.0, 0.0 ), point( 10.0, 10.0 ) );
    }

    // if we gothere, unknwon world
    BOOST_THROW_EXCEPTION( unknown_rawseeds_world_exception() );
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
