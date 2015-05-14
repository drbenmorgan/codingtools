cmake_minimum_required(VERSION 2.8.11)

project(CMakeUsageRequirements)

cmake_policy(GET CMP0025 thisClang)
message(STATUS "CMP0025: ${thisClang}")
message(STATUS "CMAKE_CXX_COMPILER_ID     : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")

if(CMAKE_VERSION VERSION_GREATER 3.0.9999)
  add_subdirectory(compiler_features)
endif()

