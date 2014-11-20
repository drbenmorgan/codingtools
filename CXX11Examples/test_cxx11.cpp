// - Dumb program to act as the executable
// Standard Library
#include <iostream>

// Third Party
// - A

// This Project
#include "TCXX/Modulus.h"

int main(int /*argc*/, char** /*argv*/) {
  std::cout << "[test_cxx11] mode : startup" << std::endl;
  std::cout << "27 (mod 26) : " << tcxx::modulo(27, 26) << std::endl;
  std::cout << "5 (mod 26) : " << tcxx::modulo(5, 26) << std::endl;
  std::cout << "-2 (mod 26) : " << tcxx::modulo(-2, 26) << std::endl;

  return 0;
}
