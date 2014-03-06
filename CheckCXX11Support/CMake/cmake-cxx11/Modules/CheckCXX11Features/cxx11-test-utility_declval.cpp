#include <utility>

struct Default {
  int foo() const {return 1;}
};

struct NonDefault {
  NonDefault(const NonDefault&) {}
  int foo() const {return 1;}
};

int main(int argc, const char *argv[])
{
  decltype(Default().foo()) n1 = 42;
  decltype(std::declval<NonDefault>().foo()) n2 = n1;
  return (n2 == 42) ? 0 : 1;
}
