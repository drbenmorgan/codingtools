# - Build script for ROOT6 testing
cmake_minimum_required(VERSION 3.2)
project(RootSixTests)

include_directories(${PROJECT_BINARY_DIR})

# - Locate ROOT6, basically assume it's been installed using CMake
# so the code gen macros/functions are available
find_package(ROOT 6.2.0 REQUIRED Core Rint)
#include(${ROOT_USE_FILE}) <- This uses add_definitions with C++ specific
# flags, thereby messing up compiliation of mixed C/C++ sources
include(${ROOT_DIR}/modules/RootNewMacros.cmake)
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
  ${PROJECT_SOURCE_DIR}/MyConfig.hpp
  MODULE RootSixTests
  LINKDEF ${PROJECT_SOURCE_DIR}/RootSixLinkDef.h
  )
add_library(RootSixTests SHARED DICT_RootSixTests.cxx Foo.hpp Foo.cpp MyConfig.hpp)
target_link_libraries(RootSixTests ${ROOT_LIBRARIES})


# - Store class in branch of TTree
# - Schema evolution with ClassDef (and/or TClass::GetCheckSum?)
# Create dictionaries for external types?
# - In general, have issues due to deeply nested template types
#   that we can't (easily) fully define (Boost), or non-default
#   constructible objects (Poco)
#find_package(Boost 1.58.0 REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})
#find_package(Poco 1.6 REQUIRED Foundation)

#root_generate_dictionary(DICT_ExternalTypes
#  ${PROJECT_SOURCE_DIR}/ExternalTypes.h
#  MODULE ExternalTypes
#  LINKDEF ${PROJECT_SOURCE_DIR}/ExternalTypesLinkDef.h
#  )
#add_library(ExternalTypes SHARED DICT_ExternalTypes.cxx)
#target_link_libraries(ExternalTypes ${ROOT_LIBRARIES} Poco::Foundation)

#-----------------------------------------------------------------------
# Create simple variant like class but with custom streamer to output
# extra info - the type index and the value itself.
root_generate_dictionary(DICT_Simple
  ${PROJECT_SOURCE_DIR}/Simple.hpp
  ${PROJECT_SOURCE_DIR}/TypeWrapper.h
  ${PROJECT_SOURCE_DIR}/Properties.h
  MODULE Simple
  LINKDEF ${PROJECT_SOURCE_DIR}/SimpleLinkDef.h
  )
# NB: For ROOT plugins to work, need to have .so ext
add_library(Simple SHARED DICT_Simple.cxx Simple.hpp Simple.cxx)
set_target_properties(Simple PROPERTIES SUFFIX ".so")

target_link_libraries(Simple ${ROOT_LIBRARIES})
add_executable(SimpleRW SimpleRW.cxx)
target_link_libraries(SimpleRW Simple)


#-----------------------------------------------------------------------
# Dynamic tests
add_executable(testDynamic testDynamic.cpp)
set_property(TARGET testDynamic PROPERTY CXX_STANDARD 14)



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

