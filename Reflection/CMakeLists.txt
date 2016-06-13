cmake_minimum_required(VERSION 3.3)
project(Reflection)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Ponder REQUIRED)

include_directories(${PONDER_INCLUDE_DIR})

# Library for the core type(s)
add_library(Person SHARED Person.hpp Person.cpp)

# Library for the reflection symbols for the core type(s)
add_library(Person_ponder SHARED ponderPerson.cpp)
target_link_libraries(Person_ponder Person ponder::ponder)

# Program that just uses the core type, loads the library
add_executable(basicPonder basicPonder.cpp)
target_link_libraries(basicPonder Person ponder::ponder)

# Program that only loads the reflection layer
add_executable(hiddenPonder hiddenPonder.cpp)
target_link_libraries(hiddenPonder ponder::ponder)

# AutoStaticInit to show the other way of loading
add_subdirectory(AutoStaticInit)

