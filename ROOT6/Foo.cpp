#include "Foo.hpp"

#include <iostream>

namespace rootsix {
void hello(const char* msg) {
  std::cout << "[hello]: " << msg <<std::endl;
}


void foo::doWork() const {
  std::cout << "foo doing work on value : " << value << std::endl;
}

void foo::setValue(int v) {
  value = v;
}

} // namespace rootsix
