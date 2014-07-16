// - Dumb program to act as the executable
// Standard Library
#include <iostream>

// Third Party
// - A

// This Project
//! Stringify supplied argument
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

namespace CMOProgram {
//! Return mode in which this exe was built
std::string getBuildMode() {
#if defined(CMO_BUILD_TYPE)
  return TOSTRING(CMO_BUILD_TYPE);
#else
  return "UNDEFINED";
#endif
}
} // namespace CMOProgram

int main(int argc, char *argv[]) {
  std::cout << "[CMOProgram] mode : " << CMOProgram::getBuildMode() << std::endl;
  return 0;
}
