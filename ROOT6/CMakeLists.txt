# - Build script for ROOT6 testing
cmake_minimum_required(VERSION 3.2)
project(RootSixTests)

# - Locate ROOT6, basically assume it's been installed using CMake
# so the code gen macros/functions are available
find_package(ROOT 6.2.0 REQUIRED)
include(${ROOT_USE_FILE})

#-----------------------------------------------------------------------
# Stuff to do:
# - Create simple class, dictionary and rlibmap file
# - Store class in branch of TTree
# - Schema evolution with ClassDef (and/or TClass::GetCheckSum?)


