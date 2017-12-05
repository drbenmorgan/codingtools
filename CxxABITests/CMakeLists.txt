cmake_minimum_required(VERSION 3.5)
project(CxxABITests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(minicanvas SHARED minicanvas.h minicanvas.cc demangle.h demangle.cc)

# - Clang/libc++/libc++abi only at the moment
#   Needs testing on other platforms, plus libc++ with different ABI...
target_link_libraries(minicanvas PRIVATE c++abi)

# Tests
add_executable(smoketest smoketest.cc)
target_link_libraries(smoketest minicanvas)

