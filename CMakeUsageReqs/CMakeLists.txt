cmake_minimum_required(VERSION 2.8.11)

project(CMakeUsageRequirements)

#-----------------------------------------------------------------------
# We should be able to set features, even if they are not available
# Don't want vendor extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# - Note that CMAKE_CXX_KNOWN_FEATURES lists those features that CMake
# knows about, which may not correspond to those supported by the
# compiler in use.
message(STATUS "List of known CXX features")
get_property(_cxx_known_features GLOBAL PROPERTY CMAKE_CXX_KNOWN_FEATURES)
foreach(_f ${_cxx_known_features})
  message("  ${_f}")
endforeach()

# - whereas CMAKE_CXX_COMPILE_FEATURES should list those the compiler
#   actually supports
# - ?How to add further checks for features not
message(STATUS "List of supported CXX features")
get_property(_cxx_compile_features GLOBAL PROPERTY CMAKE_CXX_COMPILE_FEATURES)
foreach(_f ${CMAKE_CXX_COMPILE_FEATURES})
  message("  ${_f}")
endforeach()


#-----------------------------------------------------------------------
# Now start adding targets and exporting to see how properties and so
# on are handled

add_library(test_cxx_features SHARED test_cxx_features.cpp)

# Can only set standard to 98/11/14, but CMake should do the right thing
# here (i.e. set -std=c++1y if C++14 is requested). Note however that
# it doesn't know about -std=c++0x on GCC prior to 4.7, so that's
# really the minimum GNU version that can be supported. Clang support
# appears better here.
# CMake 3.1 also won't do anything for Intel or MSVC yet.
set_property(TARGET test_cxx_features PROPERTY CXX_STANDARD 11)
set_property(TARGET test_cxx_features
  APPEND PROPERTY COMPATIBLE_INTERFACE_STRING CXX_STANDARD)

# Must set required standard to ON to prevent decay to older standard
# if requested not available (e.g. our code has workarounds to support
# an older standard).
set_property(TARGET test_cxx_features PROPERTY CXX_STANDARD_REQUIRED ON)

#-----------------------------------------------------------------------
# Install exports - want to see how compiler features are exported.
export(TARGETS test_cxx_features FILE test_cxx_features_libdeps.cmake)

install(TARGETS test_cxx_features
  EXPORT test_cxx_features
  DESTINATION lib
  )
install(EXPORT test_cxx_features DESTINATION lib/cmake)

