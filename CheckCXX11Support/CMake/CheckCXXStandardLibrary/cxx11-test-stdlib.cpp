// - Which Standard C++ library are we using?
// NB: Can probably replace this with Boost's Predef system, though
// requires Boost or a bcp import.
//
// Copyright (c) 2014, Ben Morgan <bmorgan.warwick@gmail.com>
//
// Distributed under the OSI-approved BSD 3-Clause License (the "License");
// see accompanying file License.txt for details.
//
// This software is distributed WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the License for more information.

#include <iostream>

int main() {
#if defined(_LIBCPP_VERSION)
  std::cout << "libc++(" << _LIBCPP_VERSION << ")";
#elif defined(__GLIBCXX__)
  std::cout << "libstdc++(" << __GLIBCXX__ << ")";
#else
  std::cout << "unknown(unknown)";
#endif
  return 0;
}
