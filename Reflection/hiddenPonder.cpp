#include <iostream>

#include "ponder/classbuilder.hpp"
#include "ponder/class.hpp"
#include "ponder/pondertype.hpp"
#include "ponder/classvisitor.hpp"

#include "MyObserver.hpp"

#include <dlfcn.h>

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

    // If you try and call an unknown function, an exception is thrown
    //john.call("foo");

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

/// print all classes known to ponder
void listClasses() {
  for (size_t i {0}; i < ponder::classCount(); ++i) {
    std::cout << "class " << i << ", " << ponder::classByIndex(i).name() << "\n";
  }
}

int main() {
  // Register observer
  ponder::addObserver(new MyObserver);

  // What does ponder know about?
  std::cout << "Before declare called:\n";
  listClasses();

  // Now load Person's reflection layer
  typedef void (*PonderLoadFunction)();

  // NB, no error handling yet!
  void* handle = dlopen("libPerson_ponder.dylib", RTLD_LAZY);
  PonderLoadFunction init_fcn = (PonderLoadFunction) dlsym(handle, "loadPonder");
  init_fcn();

  std::cout << "After declare called:\n";
  listClasses();

  use();
  query();
  visit();
  return 0;
}
