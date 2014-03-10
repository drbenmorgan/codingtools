#include <system_error>

int main()
{
  bool res(false);
  try {
    throw std::system_error(std::make_error_code(std::errc::io_error), "i must be thrown");
  } catch (const std::system_error& e) {
    res = true;
  }
  return res ? 0 : 1;
}
