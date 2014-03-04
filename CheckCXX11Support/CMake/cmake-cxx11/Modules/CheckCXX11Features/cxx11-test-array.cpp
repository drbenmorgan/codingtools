#include <array>

int main()
{
  std::array<char, 3> charArray{{'a', 'b', 'c'}};
  std::array<int, 3> intArray = {1, 2, 3};

  bool ret = (
      (charArray.size() == 3) &&
      (intArray.size() == 3)
      );

  return ret ? 0 : 1;
}

