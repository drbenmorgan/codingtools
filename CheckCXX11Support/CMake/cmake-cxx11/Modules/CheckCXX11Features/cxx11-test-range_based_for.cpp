#include <vector>

int main()
{
  int array[5] = {1,2,3,4,5};
  int accumulateArray(0);
  for (int i : array) {
    accumulateArray+=i;
  }

  std::vector<int> vec;
  int accumulateVector(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);

  for (int j : vec) {
    accumulateVector+=j;
  }

  return ((accumulateArray == 15) && (accumulateVector == 15)) ? 0 : 1;
}
