#include <string>

int main()
{
  std::string str1("42");
  std::string str2("3.14");
  std::string str3("314 and blah");
  int foo(42);

  bool res = ((std::stoi(str1) == 42) &&
              (std::stoi(str2) == 3) &&
              (std::stoi(str3) == 314) &&
              (std::to_string(foo) == str1));

  return res ? 0 : 1;
}

