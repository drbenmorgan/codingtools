#include <vector>
#include <algorithm>

bool isOdd(int x) {
  return (x % 2);
}

int main()
{
  std::vector<int> a;
  a.push_back(1);
  a.push_back(7);
  a.push_back(5);
  a.push_back(3);
  a.push_back(9);
  a.push_back(2);
  a.push_back(4);
  a.push_back(6);
  a.push_back(8);
  a.push_back(10);

  std::vector<int>::iterator partPoint = std::partition_point(a.begin(), a.end(), isOdd);
  
  return ((*partPoint == 2) && (*(--partPoint) == 9)) ? 0 : 1;
}
