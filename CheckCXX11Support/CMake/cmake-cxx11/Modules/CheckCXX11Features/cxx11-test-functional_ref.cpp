#include <functional>

int main()
{
  int foo(1);
  std::reference_wrapper<int> bar = std::ref(foo);

  ++bar;

  return (foo == 2) ? 0 : 1;
}
