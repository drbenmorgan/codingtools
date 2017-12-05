add_library(foo-object OBJECT
  ${CMAKE_CURRENT_LIST_DIR}/foo.h
  ${CMAKE_CURRENT_LIST_DIR}/foo.cc
  )
target_include_directories(foo-object
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
  )
target_compile_definitions(foo-object PRIVATE FOO_BUILD)
