#include <functional>

int dividor(int a, int b) {
  return a / b;
}

struct CustomPair {
  int a, b;
  int divideMe() {
    return a / b;
  }
};

int main()
{
  std::function<int()> fnOneTwo = std::bind(dividor,4,2); 
  bool fnOneTwoRes = (fnOneTwo() == 2);

  std::function<int(int)> fnOnePlace = std::bind(dividor, std::placeholders::_1, 2);
  bool fnOnePlaceRes = ((fnOnePlace(4) == 2) && (fnOnePlace(10) == 5)); 

  std::function<int(int,int)> fnReverse = std::bind(dividor, std::placeholders::_2, std::placeholders::_1);
  bool fnReverseRes = (fnReverse(5,10) == 2);

  std::function<int(CustomPair)> fnMember = std::bind(&CustomPair::divideMe,std::placeholders::_1);
  CustomPair cpFourTwo = {4, 2};
  bool cpFourTwoRes = (fnMember(cpFourTwo) == 2);

  std::function<int(CustomPair)> fnData = std::bind(&CustomPair::a, std::placeholders::_1);
  CustomPair cpFiveTen = {10, 5};
  bool cpFiveTenRes = (fnData(cpFiveTen) == 10);

  return (fnOneTwoRes && fnOnePlaceRes && fnReverseRes && cpFourTwoRes && cpFiveTenRes) ? 0 : 1;
}
