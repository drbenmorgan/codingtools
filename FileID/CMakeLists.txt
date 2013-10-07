# - Top level CMake script for FileID project
#
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(FileID)

list(INSERT CMAKE_MODULE_PATH 0 "${PROJECT_SOURCE_DIR}/cmake")

find_package(LibMagic REQUIRED)

include_directories(${LIBMAGIC_INCLUDE_DIRS})

add_executable(testLibMagic testLibMagic.cc)
target_link_libraries(testLibMagic ${LIBMAGIC_LIBRARIES})

