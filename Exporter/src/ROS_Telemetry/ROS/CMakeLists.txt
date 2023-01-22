add_library(ROS "")

target_sources(ROS
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ROS.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/ROS.hpp
  )

target_include_directories(ROS
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  )
#include_directories(src/Coms)