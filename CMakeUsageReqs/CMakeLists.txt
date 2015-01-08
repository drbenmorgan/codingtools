cmake_minimum_required(VERSION 2.8.11)
project(CMakeUsageRequirements)

if(CMAKE_VERSION VERSION_GREATER 3.0.9999)
  add_subdirectory(compiler_features)
endif()

