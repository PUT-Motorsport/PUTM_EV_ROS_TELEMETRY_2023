add_library(Loki "")

target_sources(Loki
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Loki.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Loki.hpp
  )

target_include_directories(Loki
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  )
