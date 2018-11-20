cmake_minimum_required( VERSION 2.8 )
project( draw )

set ( CMAKE_CXX_COMPILE "g++" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

find_package( Sophus REQUIRED )
find_package( Pangolin REQUIRED)

message( "Pangolin path is:${Pangolin_INCLUDE_DIRS} and ${Pangolin_LIBRARIES}" )

include_directories( ${Sophus_INCLUDE_DIRS} )
include_directories( ${Pangolin_INCLUDE_DIRS} )
include_directories( "/usr/include/eigen3" )

add_executable( draw
    draw_trajectory.cpp
)

target_link_libraries( draw
    ${Sophus_LIBRARIES}
    ${Pangolin_LIBRARIES}
)
