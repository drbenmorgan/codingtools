#include "minicanvas.h"

#include <string>

int
main(int argc, const char *argv[])
{
  art::detail::printParents(typeid(int));
  art::detail::printParents(typeid(std::string));
  return 0;
}
