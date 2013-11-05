cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME p2l-rawseeds-experiments)
include(cmake/pods.cmake)

# # automatically build LCM types.  This also defines a number of CMake
# # variables, see cmake/lcmtypes.cmake for details
# include(cmake/lcmtypes.cmake)
# lcmtypes_build()



add_definitions( -std=c++0x -Wall -fdiagnostics-show-option )
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")

option ( USE_PEDANTIC "Turn on -pendantic mode in gcc. This will spit out *lots* of warnings from lcm :-(, but hopefully none from the rest of the code" OFF)
if( USE_PEDANTIC )
    add_definitions( -pedantic )
endif (USE_PEDANTIC)



add_executable( p2l-rawseeds-experiments-runner
  src/data_loader.cpp
  src/runner.cpp
)
pods_use_pkg_config_packages( p2l-rawseeds-experiments-runner
  boost-1.54.0
  boost-1.54.0-program-options
  p2l-common
  p2l-math-core lcmtypes_p2l-math-core
  p2l-point-process-core 
  p2l-probability-core lcmtypes_p2l-probability-core
  p2l-probability-core-graphics 
  p2l-igmm-point-process  lcmtypes_p2l-igmm-point-process
  p2l-ruler-point-process
  p2l-planner-core
  p2l-point-process-experiment-core
  )
pods_install_executables( p2l-rawseeds-experiments-runner )
