#include <functional>

int dividor(int a, int b) {
  return a/b;
}

struct CustomPair {
  int a, b;
  int divideMe() {
    return a / b;
  }

  int operator()(int i) const {
    return i*2;
  }
};

int main()
{
  std::function<int(int,int)> fnDiv = dividor;
  std::function<int(CustomPair&)> csDiv = &CustomPair::divideMe;
  std::function<int(int)> csCallable = CustomPair();
  
  CustomPair foo = {9,3};

  return ((fnDiv(10,5) == 2) &&
          (csDiv(foo) == 3) &&
          (csCallable(7) == 14)) ? 0 : 1;
}
