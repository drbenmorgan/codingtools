#include <system_error>

int main()
{
  throw std::system_error(std::make_error_code(std::errc::io_error), "I must be thrown");
  return 1;
}
