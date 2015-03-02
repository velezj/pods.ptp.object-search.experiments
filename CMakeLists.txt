cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME p2l-rawseeds-experiments)
include(cmake/pods.cmake)

cmake_policy( SET CMP0045 OLD )
cmake_policy( SET CMP0026 OLD )

add_definitions( -std=c++0x -Wall -fdiagnostics-show-option -Wno-unused-local-typedefs -fPIC )
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")

option ( USE_PEDANTIC "Turn on -pendantic mode in gcc. This will spit out *lots* of warnings from lcm :-(, but hopefully none from the rest of the code" OFF)
if( USE_PEDANTIC )
    add_definitions( -pedantic )
endif (USE_PEDANTIC)

add_definitions( -DINSTALL_DIR="${CMAKE_INSTALL_PREFIX}" )
install( DIRECTORY data DESTINATION . )

add_library( p2l-rawseeds-experiments SHARED
  src/planners.cpp
  src/models.cpp
  src/register.cpp
  src/data_loader.cpp
)
pods_use_pkg_config_packages( p2l-rawseeds-experiments
  boost-1.54.0
  p2l-common
  p2l-math-core
  p2l-point-process-core 
  p2l-probability-core
  p2l-igmm-point-process
  p2l-ruler-point-process
  p2l-planner-core
  p2l-point-process-experiment-core
  ptp.object-search.point-process-entropy-planners
)
pods_install_headers(
  src/models.hpp
  src/planners.hpp
  src/register.hpp
  src/data_loader.hpp
  DESTINATION
  p2l-rawseeds-experiments
)
pods_install_libraries( p2l-rawseeds-experiments )
pods_install_pkg_config_file(p2l-rawseeds-experiments
    CFLAGS
    LIBS -lp2l-rawseeds-experiments
    REQUIRES boost-1.54.0 p2l-common p2l-math-core p2l-point-process-core p2l-probability-core p2l-igmm-point-process p2l-ruler-point-process p2l-planner-core ptp.object-search.point-process-entropy-planners p2l-point-process-experiment-core
    VERSION 0.0.1)



add_executable( p2l-rawseeds-experiments-runner
  src/runner.cpp
)
pods_use_pkg_config_packages( p2l-rawseeds-experiments-runner
  p2l-rawseeds-experiments
  git-version-script
  boost-1.54.0-program-options
)
pods_install_executables( p2l-rawseeds-experiments-runner )


add_executable( p2l-rawseeds-experiments-console
  src/console.cpp
)
pods_use_pkg_config_packages( p2l-rawseeds-experiments-console
  p2l-rawseeds-experiments
  boost-1.54.0-program-options
)
pods_install_executables( p2l-rawseeds-experiments-console )


add_executable( p2l-rawseeds-experiments-info
  src/info.cpp
)
pods_use_pkg_config_packages( p2l-rawseeds-experiments-info
  p2l-rawseeds-experiments
  boost-1.54.0-program-options
)
pods_install_executables( p2l-rawseeds-experiments-info )


add_subdirectory( test )