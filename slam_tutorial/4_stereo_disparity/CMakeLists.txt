cmake_minimum_required( VERSION 2.8 )
project( disparity )

set( CMAKE_CXX_COMPILE "g++" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

set(CMAKE_PREFIX_PATH "/home/fqy/dependency/OpenCV330/")

find_package( Sophus REQUIRED )
find_package( Pangolin REQUIRED)
find_package( Eigen3 REQUIRED )
find_package( OpenCV REQUIRED )

include_directories( ${Sophus_INCLUDE_DIRS} )
include_directories( ${Pangolin_INCLUDE_DIRS} )
include_directories( ${EIGEN3_INCLUDE_DIRS} )
include_directories( ${OpenCV_INCLUDE_DIRS} )

message( "Eigen3 INCLUDE PATH = ${EIGEN3_INCLUDE_DIRS}")
message( "OpenCV include_path:${OpenCV_INCLUDE_DIRS} and lib path:${OpenCV_LIBRARY}")


add_executable( ${PROJECT_NAME}
    compute_disparity.cpp
)

target_link_libraries( ${PROJECT_NAME}
    ${Sophus_LIBRARIES}
    ${Pangolin_LIBRARIES}
    ${EIGEN3_LIBS}
    ${OpenCV_LIBS}
)
