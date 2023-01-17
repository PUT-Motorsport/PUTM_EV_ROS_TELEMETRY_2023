add_library(Prometheus "")

target_sources(Prometheus
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Prometheus.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Prometheus.hpp
  )

target_include_directories(Prometheus
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  )
#include_directories(src/Coms)