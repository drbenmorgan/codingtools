cmake_minimum_required(VERSION 3.2)
project(SystemMetadata)

#-----------------------------------------------------------------------
# We should be able to set features, even if they are not available
# Don't want vendor extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# Want C++11 by default
set(CMAKE_CXX_STANDARD 11)

#-----------------------------------------------------------------------
# Linux specific stuff
#
add_executable(linux_program linux_program.cpp)


