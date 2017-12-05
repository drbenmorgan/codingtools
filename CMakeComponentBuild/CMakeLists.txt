cmake_minimum_required(VERSION 3.3)
project(CMakeComponentBuild)

include(CMakeParseArguments)

function(ccb_init)
  # - Initialise global properties
  set_property(GLOBAL PROPERTY CCB_COMPONENTS)
  set_property(GLOBAL PROPERTY CCB_PRODUCTS)
endfunction()

function(ccb_display_property _pname)
  get_property(_tmp GLOBAL PROPERTY CCB_${_pname})
  message(STATUS "[ccb:${_name}] = ${_tmp}")
endfunction()

function(ccb_is_enabled _name _var)
  get_property(_tmp GLOBAL PROPERTY CCB_COMPONENTS)
  list(FIND _tmp ${_name} _has_component)
  if(_has_component GREATER -1)
    set(${_var} TRUE PARENT_SCOPE)
  else()
    set(${_var} FALSE PARENT_SCOPE)
  endif()
endfunction()

function(ccb_add_component _name)
  message(STATUS "ccb_add_component(${_name})")

  ccb_is_enabled(${_name} _known)
  if(${_known})
    message(FATAL_ERROR "Component with ${_name} already defined!")
  else()
    set_property(GLOBAL APPEND PROPERTY CCB_COMPONENTS ${_name})
    # Direct properties of component
    # set_property(GLOBAL APPEND PROPERTY CCB_COMPONENT_${_name}_<ATTRIBUTE>)
  endif()
endfunction()

# function(ccb_component_link_libraries _name PUBLIC PRIVATE INTERFACE)
# internally, this should handle the include dirs etc...
# though still need to define these for externals and local interface


# - ensure clean startup
ccb_init()

# - define components
ccb_add_component(foo)
# ? Others to follow cmake conventions?
# Efectively, a component is a "delayed" target, and things may need to
# be applied to the target or the product which uses it.
# For the oddities currently present in object libs and so on, see
# http://thread.gmane.org/gmane.comp.programming.tools.cmake.devel/7082
#http://thread.gmane.org/gmane.comp.programming.tools.cmake.devel/9705/focus=9722
# Object libs would be ideal, but, we can define links for them directly,
# and also final linking is between products, not components (i.e. when
# linking a product, we work out what components it's composed of, then
# determine which components they depend on, and finally the list of
# products containing those components (For both public and private!)
#
#ccb_component_include_directories()
#ccb_component_link_libraries()
#ccb_component_compile_options()

ccb_add_component(bar)
ccb_add_component(baz)

# Resolve DAG - i.e. check for any deps not defined in components
# ccb_resolve_components()

# Build Products
# - Requires components to be defined, so those need to be "loaded" somehow,
# e.g. recurson to their directories, or inclusion of relevant CMake "module"
# files
# Products are declarative, and a component cannot be added into more than
# one product
#ccb_add_products()
# - ccb_add_product(NAME comp1 comp2 ... compN)
# Need to ensure that products don't use a component more than once.
# Also need to check for unused components
#ccb_resolve_targets (need to work out linking...)
# Need to resolve deps on components to deps on products

ccb_display_property(COMPONENTS)

#-----------------------------------------------------------------------
# CMake's OBJECT libs may provide a good model for building components
# if they are to go into an overall library.
# Can we create object libs and compose them?
include(foo/sources.cmake)

add_library(foobar $<TARGET_OBJECTS:foo-object>)

# group sources?
get_target_property(foosrcs foo-object SOURCES)
source_group(foobar\\foo FILES ${foosrcs})
