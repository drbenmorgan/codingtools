#include <system_error>

int main()
{
  bool res(false);
  try {
    throw std::system_error();
  } catch (const std::system_error& e) {
    res = true;
  }
  return res ? 0 : 1;
}
