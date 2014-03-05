#include <system_error>

int main()
{
  throw std::system_error();
  return 1;
}
