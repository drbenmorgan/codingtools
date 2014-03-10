#include <vector>
#include <algorithm>

bool isOdd(int x) {
  return (x % 2);
}

int main()
{
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_back(5);
  a.push_back(6);
  a.push_back(7);
  a.push_back(8);
  a.push_back(9);
  a.push_back(10);

  bool aRes = std::is_partitioned(a.begin(), a.end(), isOdd);

  std::vector<int> b;
  b.push_back(1);
  b.push_back(3);
  b.push_back(5);
  b.push_back(7);
  b.push_back(9);
  b.push_back(2);
  b.push_back(4);
  b.push_back(6);
  b.push_back(8);
  b.push_back(10);
  
  bool bRes = std::is_partitioned(b.begin(), b.end(), isOdd);

  return (!aRes && bRes) ? 0 : 1;
}
