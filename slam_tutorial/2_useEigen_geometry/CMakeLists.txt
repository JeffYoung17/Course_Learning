cmake_minimum_required( VERSION 2.8 )
project( useEigen )
set ( CMAKE_CXX_COMPILE "g++" )

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

include_directories( ${PROJECT_SOURCE_DIR}/include )
include_directories( "/usr/include/eigen3" )


add_executable( ${PROJECT_NAME}
    src/useEigen.cpp
)

