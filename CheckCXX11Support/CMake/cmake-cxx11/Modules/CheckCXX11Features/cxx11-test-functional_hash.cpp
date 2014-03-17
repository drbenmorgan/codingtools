#include <functional>
#include <string>

int main()
{
  std::hash<double> dHash;
  std::hash<std::string> sHash;

  return ((dHash(3.14) == dHash(3.14)) &&
          (dHash(3.14) != dHash(3.13)) && 
          (sHash("FooBarBaz") == sHash("FooBarBaz"))) ? 0 : 1;
}

