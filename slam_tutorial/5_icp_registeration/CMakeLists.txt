cmake_minimum_required( VERSION 2.8 )
project( match )

set( CMAKE_CXX_COMPILE "g++" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )
set(CMAKE_PREFIX_PATH "/home/fqy/dependency/OpenCV330/")

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules )

find_package( Sophus REQUIRED )
find_package( Pangolin REQUIRED)
find_package( Eigen3 REQUIRED )
find_package( OpenCV REQUIRED )
find_package( Ceres REQUIRED )
find_package( G2O REQUIRED )

include_directories( ${Sophus_INCLUDE_DIRS} )
include_directories( ${Pangolin_INCLUDE_DIRS} )
include_directories( ${EIGEN3_INCLUDE_DIRS} )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${CERES_INCLUDE_DIRS} )
include_directories( ${G2O_INCLUDE_DIRS} )

message( "Eigen3 INCLUDE PATH = ${EIGEN3_INCLUDE_DIRS}")
message( "OpenCV include_path:${OpenCV_INCLUDE_DIRS} and lib path:${OpenCV_LIBS}")
message( "Ceres include_path:${CERES_INCLUDE_DIRS} and lib path:${CERES_LIBRARIES}")
message( "G2O include_path:${G2O_INCLUDE_DIRS} and lib path:${G2O_LIBRARIES}")

add_executable( ${PROJECT_NAME}
    ba_method.cpp
    # svd_method.cpp
)

target_link_libraries( ${PROJECT_NAME}
    ${Sophus_LIBRARIES}
    ${Pangolin_LIBRARIES}
    ${EIGEN3_LIBS}
    ${OpenCV_LIBS}
    ${CERES_LIBRARIES}
    g2o_core g2o_stuff
)
