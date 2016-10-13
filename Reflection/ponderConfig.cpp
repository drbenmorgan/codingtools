#include "Config.hpp"

#include <iostream>

#include "ponder/classbuilder.hpp"
#include "ponder/class.hpp"
#include "ponder/pondertype.hpp"
extern "C" void loadPonder() {
  // should only be called once, but safe to call further
  // We just need to explicitly instantiate.
  // Not clear if this can be partitioned out into a separate translation unit
  // i.e. one declare_X function for each reflected type, one "loadPonder"
  // function to ensure instantiation...
  ponder::classByType<Config>();
}

void declare_config() // register details (once)
{
  std::cout << "called declare_config\n";
    ponder::Class::declare<Config>("Config")
        .property("count", &Config::count)
        .property("strategy", &Config::strategy)
        ;
}

PONDER_AUTO_TYPE(Config, &declare_config) // declare type
