add_library(Parser "")

target_sources(Parser
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Parser.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Parser.hpp
  )

target_include_directories(Parser
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  )
#include_directories(src/Coms)