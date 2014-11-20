//  - baz does bar
// Basic idea is to improve and ease use of I/O, introducing control
// structures along the way. Potential to also demo comman line args
// either via getopt or Boost program_options (latter to be balanced
// against complexity and need to find/link).
// Copyright (c) 2014 by Ben Morgan <bmorgan.warwick@gmail.com>
// Copyright (c) 2014 by The University of Warwick

#include <iostream>
#include <algorithm>
#include <iterator>

#if defined(HAVE_GETOPT)
#include "unistd.h"
#endif

int main(int argc, char *argv[])
{
  std::cout << "Number of arguments = " << argc << std::endl;

  for (int i(0); i < argc; i++) {
    std::cout << "argv[" << i << "] = '" << argv[i] << "'" << std::endl;
  }



  // This allows reading from keyboard or redirection.
  // From Keyboard, use Ctrl-D to end?
  // See http://stackoverflow.com/questions/7232297/redirecting-input-using-stdin
  std::copy(std::istream_iterator<char>(std::cin),
            std::istream_iterator<char>(),
            std::ostream_iterator<char>(std::cout, ","));
  std::cout << "finish" << std::endl;
  return 0;
}
