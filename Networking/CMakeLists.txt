cmake_minimum_required(VERSION 3.1.0)
project(SimpleNetworkTasks)

# - Require C++11 and no vendor extensions
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find Boost with asio library
find_package(Boost 1.57.0 COMPONENTS date_time system)

# Find CURL
find_package(CURL REQUIRED)

add_library(SimpleNetworkTasks SHARED
  check_network.hpp
  check_network.cpp
  )


#-----------------------------------------------------------------------
# Tests
#
enable_testing()

if(Boost_FOUND)
  add_executable(testBoostAsio testBoostAsio.cpp)
  target_include_directories(testBoostAsio PRIVATE ${Boost_INCLUDE_DIRS})
  target_link_libraries(testBoostAsio ${Boost_DATE_TIME_LIBRARY} ${Boost_SYSTEM_LIBRARY})
  add_test(testBoostAsio testBoostAsio)
endif()

# Default test connections...
add_executable(testNetworkConnection testNetworkConnection.cpp)
target_link_libraries(testNetworkConnection SimpleNetworkTasks)
add_test(testNetworkConnection testNetworkConnection)

# Use libCurl
add_executable(testLibCurl testLibCurl.cpp)
target_link_libraries(testLibCurl ${CURL_LIBRARIES})
target_include_directories(testLibCurl PRIVATE ${CURL_INCLUDE_DIRS})
add_test(testLibCurl testLibCurl)


