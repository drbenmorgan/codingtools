#include "Person.hpp"

#include <iostream>

#include "ponder/classbuilder.hpp"
#include "ponder/class.hpp"
#include "ponder/pondertype.hpp"

namespace libPerson {
void loadPonder() {
  // should only be called once, but safe to call further
  // We just need to explicitly instantiate.
  // Not clear if this can be partitioned out into a separate translation unit
  // i.e. one declare_X function for each reflected type, one "loadPonder"
  // function to ensure instantiation...
  ponder::classByType<Person>();
}

} // namespace Person


void declare_person() // register details (once)
{
  std::cout << "called declare_person\n";
    ponder::Class::declare<Person>("Person")
        .constructor<std::string>()
        .property("name", &Person::name)
        .property("age", &Person::age, &Person::setAge)
        .function("speak", &Person::speak)
        ;
}

PONDER_AUTO_TYPE(Person, &declare_person) // declare type
