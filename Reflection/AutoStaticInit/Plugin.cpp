#include <iostream>

namespace plugin {
void plugin() {
  std::cout << "[plugin]: hidden\n";
}
} // namespace hidden

// magic happens here?
// Find that foo is constructed before main enters.
// So for ponder, could use this to implement registration callback (if only
// require function, maybe wrap in std::function or similar?)
#include <boost/serialization/singleton.hpp>
namespace {
struct plugin_foo {
  plugin_foo() {std::cout << "plugin_foo::plugin_foo() called\n";}
};

static auto gPluginFoo = boost::serialization::singleton<plugin_foo>::get_const_instance();
}
