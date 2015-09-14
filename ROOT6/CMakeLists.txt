# - Build script for ROOT6 testing
cmake_minimum_required(VERSION 3.2)
project(RootSixTests)

include_directories(${PROJECT_BINARY_DIR})

# - Locate ROOT6, basically assume it's been installed using CMake
# so the code gen macros/functions are available
find_package(ROOT 6.2.0 REQUIRED Core Rint)
#include(${ROOT_USE_FILE}) <- This uses add_definitions with C++ specific
# flags, thereby messing up compiliation of mixed C/C++ sources
include(RootNewMacros)
include_directories(${ROOT_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${ROOT_CXX_FLAGS}")


#-----------------------------------------------------------------------
# Stuff to do:
# - Create simple class, dictionary and rlibmap file
# Note that due to limitations of Root6/Cling, need to load the library
# *and* include headers..., i.e. as per root manual:
#
# R__LOAD_LIBRARY(libNAME)
# #include "headerforiface.h"
root_generate_dictionary(DICT_RootSixTests
  ${PROJECT_SOURCE_DIR}/Foo.hpp
  MODULE RootSixTests
  LINKDEF ${PROJECT_SOURCE_DIR}/RootSixLinkDef.h
  )
add_library(RootSixTests SHARED DICT_RootSixTests.cxx Foo.hpp Foo.cpp)
target_link_libraries(RootSixTests ${ROOT_LIBRARIES})


# - Store class in branch of TTree
# - Schema evolution with ClassDef (and/or TClass::GetCheckSum?)

#-----------------------------------------------------------------------
# A simple re-interpreter
# - Generate binreloc header/source with mangled names, ensuring first
# character(s) are a valid for a C identifier
string(RANDOM LENGTH 18 MANGLE_BINRELOC_MAIN)
set(MANGLE_BINRELOC "MB${MANGLE_BINRELOC_MAIN}")
set(BINRELOC_HEADER "myinterp_BinReloc.h")
configure_file(BinReloc.h.in myinterp_BinReloc.h @ONLY)
configure_file(BinReloc.c.in myinterp_BinReloc.c @ONLY)
add_definitions(-DENABLE_BINRELOC)

# Copy resource scripts to build directory
configure_file(myconfig myconfig @ONLY)
configure_file(myinterplogon.C myinterplogon.C @ONLY)
configure_file(myinterplogoff.C myinterplogoff.C @ONLY)

add_executable(myinterp myinterp.cc myinterp_BinReloc.c)
target_link_libraries(myinterp ${ROOT_LIBRARIES})

