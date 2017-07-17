// Standard Library
#include <iostream>
// Third Party
// - A

// This Project
#include "Dynamic.h"


int main(int argc, const char *argv[])
{
  Dynamic d;
  std::cout << d.indexOf<int>() << std::endl;
  std::cout << d.indexOf<double>() << std::endl;
  std::cout << d.indexOf<bool>() << std::endl;

  std::cout << d.type() << std::endl;
  //std::cout << d.get<double>() << std::endl;

  d.set(std::vector<int> {1,2,3,4});

  std::cout << d.type() << std::endl;

  for (int& i : d.get<std::vector<int> >()) {
    std::cout << i << std::endl;
  }

  return 0;
}

