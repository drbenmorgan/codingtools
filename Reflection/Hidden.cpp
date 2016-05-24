#include "Hidden.hpp"
#include <iostream>

namespace hidden {
void hidden() {
  std::cout << "[hidden]: hidden\n";
}
} // namespace hidden

// magic happens here?
// Find that foo is constructed before main enters.
// So for ponder, could use this to implement registration callback (if only
// require function, maybe wrap in std::function or similar?)
#include <boost/serialization/singleton.hpp>
namespace {
struct foo {
  foo() {std::cout << "foo::foo() called\n";}
};

static auto gFoo = boost::serialization::singleton<foo>::get_const_instance();
}
