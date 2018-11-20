cmake_minimum_required( VERSION 2.8 )
project( sophus_demo )
set ( CMAKE_CXX_COMPILE "g++" )

find_package( Sophus REQUIRED )

include_directories( ${Sophus_INCLUDE_DIRS} )

add_executable( ${PROJECT_NAME}
    use_Sophus.cpp
)
target_link_libraries( ${PROJECT_NAME}
    ${Sophus_LIBRARIES}
)
