cmake_minimum_required( VERSION 2.8 )
project( compare )

set ( CMAKE_CXX_COMPILE "g++" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

find_package( Sophus REQUIRED )
find_package( Pangolin REQUIRED)
find_package( Eigen3 REQUIRED )

include_directories( ${Sophus_INCLUDE_DIRS} )
include_directories( ${Pangolin_INCLUDE_DIRS} )
include_directories( ${EIGEN3_INCLUDE_DIRS} )

message( "Eigen3 INCLUDE PATH = ${EIGEN3_INCLUDE_DIRS}")
message("Eigen3 LIB PATH = ${EIGEN3_LIBS}")

add_executable( compare
    compare_trajectory.cpp
)

target_link_libraries( compare
    ${Sophus_LIBRARIES}
    ${Pangolin_LIBRARIES}
    ${EIGEN3_LIBS}
)
