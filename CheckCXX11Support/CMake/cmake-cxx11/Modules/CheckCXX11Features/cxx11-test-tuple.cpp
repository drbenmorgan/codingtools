#include <tuple>

int main()
{
  std::tuple<int, char, double> aTuple(1, 'a', 3.14);
  std::tuple<int, char, double> bTuple = aTuple;
  return ((aTuple == bTuple) && (std::get<0>(aTuple) == 1)) ? 0 : 1;
}
