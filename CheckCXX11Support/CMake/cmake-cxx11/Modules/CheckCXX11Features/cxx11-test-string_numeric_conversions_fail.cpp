#include <string>

int main()
{
  std::string invalid("blah blah and 42");
  // should throw
  std::stoi(invalid);
  return 0;
}
