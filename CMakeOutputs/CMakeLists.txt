cmake_minimum_required(VERSION 2.8.11)
project(CMakeOutputs)

#-----------------------------------------------------------------------
# Use a standard GNU style install layout to begin with. Will later
# look at specializations for OSX Frameworks and Apps
#
include(GNUInstallDirs)

#-----------------------------------------------------------------------
# The variables CMAKE_{RUNTIME,LIBRARY,ARCHIVE}_OUTPUT_DIRECTORY can
# be used to specify where executables, dynamic and static libraries
# are output. They initialize the {RUNTIME,LIBRARY,ARCHIVE}_OUTPUT_DIRECTORY
# properties of targets added via add_{executable,target}, so can
# targets can override if need be.
#
# - Assume for now that GNUInstallDirs provides relative (to
#   CMAKE_INSTALL_PREFIX) paths, and reflect this layout in the
#   output directories. This should be o.k. even on DLL platforms
#   as CMake should output these to the RUNTIME directory.
#
set(BASE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/BuildProducts")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BASE_OUTPUT_DIRECTORY}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BASE_OUTPUT_DIRECTORY}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BASE_OUTPUT_DIRECTORY}/${CMAKE_INSTALL_LIBDIR}")

#-----------------------------------------------------------------------
# In multiconfig generators, each of the above paths has the config name,
# e.g. "Release" appended to them so products from different modes are
# kept separate. e.g.
#
# BuildProducts/
# +- bin/
#    +- Release/
#       +- CMOProgram
#
# If instead we want to have
#
# BuildProducts/
# +- Release/
#    +- bin/
#       +- CMOProgram
#
# then we can use the config specific variables
#
# CMAKE_{RUNTIME,LIBRARY,ARCHIVE}_OUTPUT_DIRECTORY_<CONFIG>
#
# to customize these locations. The customization will depend on
# the use cases of the project.
#
# In the simplest case, we only want to edit these when generating
# for a multiconfig tool (probably can also do this for single config
# tools, but that runs risk of leaving obsolete products lying around).
# Generation of scripts for multiconfig tool is generally indicated by
# the presence of the CMAKE_CONFIGURATION_TYPES variable.
# As an example, use the the above scheme of <BASE>/<CONFIG>/<TYPEDIR>
# to specify the config mode output dirs.
#
foreach(_conftype ${CMAKE_CONFIGURATION_TYPES})
  string(TOUPPER ${_conftype} _conftype_uppercase)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${_conftype_uppercase}
    "${BASE_OUTPUT_DIRECTORY}/${_conftype}/${CMAKE_INSTALL_BINDIR}"
    )
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${_conftype_uppercase}
    "${BASE_OUTPUT_DIRECTORY}/${_conftype}/${CMAKE_INSTALL_LIBDIR}"
    )
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${_conftype_uppercase}
    "${BASE_OUTPUT_DIRECTORY}/${_conftype}/${CMAKE_INSTALL_LIBDIR}"
    )
endforeach()

#-----------------------------------------------------------------------
# To check how products were compiled, we add in a simple config
# dependent preprocessor def that the products will pick up
#
foreach(_conftype IN LISTS CMAKE_CONFIGURATION_TYPES CMAKE_BUILD_TYPE)
  string(TOUPPER ${_conftype} _conftype_uppercase)
  set_property(DIRECTORY
    PROPERTY
      COMPILE_DEFINITIONS_${_conftype_uppercase} CMO_BUILD_TYPE=${_conftype_uppercase}
    )
endforeach()

#-----------------------------------------------------------------------
# Now the targets...
# - Executable
add_executable(CMOProgram CMOProgram.cpp)

# - Shared lib
add_library(CMOSharedLibrary SHARED CMOSharedLibrary.h CMOSharedLibrary.cpp)

# - Static lib
add_library(CMOStaticLibrary STATIC CMOStaticLibrary.h CMOStaticLibrary.cpp)


