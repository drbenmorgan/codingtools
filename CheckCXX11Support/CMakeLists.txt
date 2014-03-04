# - Top level script for CheckCXX11Support project
#
#-----------------------------------------------------------------------
# Copyright (c) 2014, Ben Morgan <bmorgan.warwick@gmail.com>
#
# Distributed under the OSI-approved BSD 3-Clause License (the "License");
# see accompanying file License.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#-----------------------------------------------------------------------

#-----------------------------------------------------------------------
# Use of the CXX11 checks requires cmake 2.8.3 at minimum, so also
# require this here
#
cmake_minimum_required(VERSION 2.8.3)
project(CheckCXX11Support)

# - Add CXX11 Modules
list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/CMake/cmake-cxx11/Modules)

# - Check Features
include(CheckCXX11Features)

#-----------------------------------------------------------------------
# Checks for headers - propbably need more than this, e.g. checks for
# function *in* headers (possibly also for TR1 namespace).
include(CheckIncludeFileCXX)

# <random>
check_include_file_cxx(random HAS_CXX_RANDOM)

# <system_error>
check_include_file_cxx(system_error HAS_CXX_SYSTEM_ERROR)

# <tuple>
check_include_file_cxx(tuple HAS_CXX_TUPLE)

# <type_traits>
check_include_file_cxx(type_traits HAS_CXX_TYPE_TRAITS)

# - Check C++ Standard Library (NB, not cross compile safe yet! Though
# if we do cross-compile, then everything should be appropriately provided
# by the toolchain?).
try_run(
  STDLIB_RUN_RESULT
  STDLIB_COMPILE_RESULT
  ${PROJECT_BINARY_DIR}/cxx_stdlib
  ${PROJECT_SOURCE_DIR}/CMake/CheckCXXStandardLibrary/cxx11-test-stdlib.cpp
  RUN_OUTPUT_VARIABLE STDLIB_OUTPUT
  )
message(STATUS "C++ Standard Library : ${STDLIB_OUTPUT}")

