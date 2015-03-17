cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME object-search.rawseeds-experiments)
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

add_library( object-search.rawseeds-experiments SHARED
  src/planners.cpp
  src/models.cpp
  src/register.cpp
  src/data_loader.cpp
)
pods_use_pkg_config_packages( object-search.rawseeds-experiments
  boost-1.54.0
  object-search.common
  object-search.math-core
  object-search.point-process-core 
  object-search.probability-core
  object-search.igmm-point-process
  object-search.ruler-point-process
  object-search.planner-core
  object-search.point-process-experiment-core
  ptp.object-search.point-process-entropy-planners
)
pods_install_headers(
  src/models.hpp
  src/planners.hpp
  src/register.hpp
  src/data_loader.hpp
  DESTINATION
  object-search.rawseeds-experiments
)
pods_install_libraries( object-search.rawseeds-experiments )
pods_install_pkg_config_file(object-search.rawseeds-experiments
    CFLAGS
    LIBS -lobject-search.rawseeds-experiments
    REQUIRES boost-1.54.0 object-search.common object-search.math-core object-search.point-process-core object-search.probability-core object-search.igmm-point-process object-search.ruler-point-process object-search.planner-core ptp.object-search.point-process-entropy-planners object-search.point-process-experiment-core
    VERSION 0.0.1)



add_executable( object-search.rawseeds-experiments-runner
  src/runner.cpp
)
pods_use_pkg_config_packages( object-search.rawseeds-experiments-runner
  object-search.rawseeds-experiments
  git-version-script
  boost-1.54.0-program-options
)
pods_install_executables( object-search.rawseeds-experiments-runner )


add_executable( object-search.rawseeds-experiments-console
  src/console.cpp
)
pods_use_pkg_config_packages( object-search.rawseeds-experiments-console
  object-search.rawseeds-experiments
  boost-1.54.0-program-options
)
pods_install_executables( object-search.rawseeds-experiments-console )


add_executable( object-search.rawseeds-experiments-info
  src/info.cpp
)
pods_use_pkg_config_packages( object-search.rawseeds-experiments-info
  object-search.rawseeds-experiments
  boost-1.54.0-program-options
)
pods_install_executables( object-search.rawseeds-experiments-info )


add_subdirectory( test )