#include <iostream>

#include "ponder/classbuilder.hpp"
#include "ponder/class.hpp"
#include "ponder/pondertype.hpp"
#include "ponder/classvisitor.hpp"

#include "Person.hpp"

void use()
{
    // Retrieve the metaclass by its name
    const ponder::Class& metaclass = ponder::classByName("Person");

    // Use the metaclass to construct a new person named John
    ponder::UserObject john = metaclass.construct(ponder::Args("John"));

    // Print its name
    std::cout << "John's name is: " << john.get("name") << std::endl;

    // Set its age to 24
    john.set("age", 24);

    // Make John say something
    john.call("speak");

    // Kill John
    metaclass.destroy(john);
}

void query() {
  const ponder::Class& metaclass = ponder::classByName("Person");

  for(size_t index {0}; index < metaclass.propertyCount(); ++index) {
    auto& prop = metaclass.property(index);
    std::cout << prop.name() << ", " << prop.type() << std::endl;
  }
}

class MyClassVisitor : public ponder::ClassVisitor
{
    void visit(const ponder::SimpleProperty& property)
    {
        std::cout << "Simple property: " << property.name() << std::endl;
    }
    void visit(const ponder::ArrayProperty& property)
    {
        std::cout << "Array property: " << property.name() << " - "
                  << "dynamic:" << property.dynamic() << std::endl;
    }
    void visit(const ponder::EnumProperty& property)
    {
        std::cout << "Enum property: " << property.name() << " - "
                  << "owner enum:" << property.getEnum().name() << std::endl;
    }
    void visit(const ponder::UserProperty& property)
    {
        std::cout << "User property: " << property.name() << " - "
                  << "owner class:" << property.getClass().name() << std::endl;
    }
    void visit(const ponder::Function& function)
    {
        std::cout << "Function: " << function.name() << " - "
                  << "number of arguments:" << function.argCount() << std::endl;
    }
};

void visit() {
  const ponder::Class& metaclass = ponder::classByName("Person");
  MyClassVisitor vis;
  metaclass.visit(vis);

}

int main() {
  declare();
  use();
  query();
  visit();
  return 0;
}
