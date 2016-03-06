cmake_minimum_required(VERSION 3.3)
project(Reflection)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Ponder REQUIRED)

include_directories(${PONDER_INCLUDE_DIR})
add_library(Person SHARED Person.hpp Person.cpp)
target_link_libraries(Person ponder::ponder)

add_executable(basicPonder basicPonder.cpp)
target_link_libraries(basicPonder Person)
