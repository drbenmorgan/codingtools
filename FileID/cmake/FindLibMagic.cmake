# - Find libmagic
# Find the native libmagic headers and libraries.
# It sets the following variables
#
# LIBMAGIC_INCLUDE_DIR  - The magic include directory (where to find magic.h)
# LIBMAGIC_LIBRARY      - The libraries to link to when using libmagic
# LIBMAGIC_FOUND        - True if libmagic is found
#

#-----------------------------------------------------------------------
# Copyright (c) 2013, Ben Morgan <bmorgan.warwick@gmail.com>
#
# Distributed under the OSI-approved BSD 3-Clause License (the "License");
# see accompanying file License.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#-----------------------------------------------------------------------

find_path(LIBMAGIC_INCLUDE_DIR NAMES magic.h)
find_library(LIBMAGIC_LIBRARY NAMES magic)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LibMagic DEFAULT_MSG LIBMAGIC_INCLUDE_DIR LIBMAGIC_LIBRARY)
mark_as_advanced(LIBMAGIC_INCLUDE_DIR LIBMAGIC_LIBRARY)
if(LIBMAGIC_FOUND)
  set(LIBMAGIC_INCLUDE_DIRS ${LIBMAGIC_INCLUDE_DIR})
  set(LIBMAGIC_LIBRARIES ${LIBMAGIC_LIBRARY})
endif()
