#include <type_traits>

int main(int argc, const char *argv[])
{
  bool res = (std::is_integral<int>::value
              && std::is_arithmetic<int>::value
              && !std::is_integral<float>::value
              && std::is_arithmetic<float>::value);
  return res ? 0 : 1;
}

