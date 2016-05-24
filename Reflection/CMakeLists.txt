cmake_minimum_required(VERSION 3.3)
project(Reflection)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Ponder REQUIRED)

include_directories(${PONDER_INCLUDE_DIR})
add_library(Person SHARED Person.hpp Person.cpp ponderPerson.cpp)
target_link_libraries(Person ponder::ponder)

add_executable(basicPonder basicPonder.cpp)
target_link_libraries(basicPonder Person)

# The oddity of Bayeux using boost::serialization's singleton. Appears to be used to
# guarantee calling of ponder registration code, so is that born out?
# - Create a library
add_library(Hidden SHARED Hidden.hpp Hidden.cpp)
add_executable(HiddenUser HiddenUser.cpp)
target_link_libraries(HiddenUser Hidden)
