#include <functional>

int main()
{
  int foo(10);
  std::reference_wrapper<const int> bar = std::cref(foo);

  ++bar;
  
  return 0;
}
