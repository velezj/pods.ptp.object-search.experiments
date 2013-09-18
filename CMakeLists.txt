cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME p2l-rawseeds-experiments)
include(cmake/pods.cmake)

# # automatically build LCM types.  This also defines a number of CMake
# # variables, see cmake/lcmtypes.cmake for details
# include(cmake/lcmtypes.cmake)
# lcmtypes_build()



add_definitions( -Wall -fdiagnostics-show-option )
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")

option ( USE_PEDANTIC "Turn on -pendantic mode in gcc. This will spit out *lots* of warnings from lcm :-(, but hopefully none from the rest of the code" OFF)
if( USE_PEDANTIC )
    add_definitions( -pedantic )
endif (USE_PEDANTIC)



