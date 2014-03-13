#include <cstddef>

int f(int* pi)
{
  return 1;
}

int f(double* pd)
{
  return 2;
}

int f(std::nullptr_t)
{
  return 3;
}

int main()
{
  int* pi;
  double* pd;
  int rpi = f(pi);
  int rpd = f(pd);
  int rnp = f(nullptr);

  return ((rpi == 1) && (rpd == 2) && (rnp == 3)) ? 0 : 1;
}
