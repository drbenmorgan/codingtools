#include "minicanvas.h"

#include <string>
#include <stdexcept>

class Base {};

template <typename T>
class TemplateClass{};

class NVConcrete : public Base {};

int
main(int argc, const char *argv[])
{
  art::detail::printParents(typeid(int));
  art::detail::printParents(typeid(std::string));
  art::detail::printParents(typeid(std::runtime_error));
  art::detail::printParents(typeid(Base));
  art::detail::printParents(typeid(NVConcrete));
  art::detail::printParents(typeid(TemplateClass<char>));
  return 0;
}
