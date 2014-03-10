#include <vector>
#include <algorithm>

bool isOdd(int x) {
  return (x % 2);
}

int main()
{
  std::vector<int> a;
  a.push_back(2);
  a.push_back(4);
  a.push_back(6);
  a.push_back(8);
  a.push_back(10);

  bool aRes = std::any_of(a.begin(), a.end(), isOdd);

  std::vector<int> b;
  b.push_back(2);
  b.push_back(4);
  b.push_back(5);
  b.push_back(8);
  b.push_back(10);

  bool bRes = std::any_of(b.begin(), b.end(), isOdd);
  
  return (!aRes && bRes) ? 0 : 1;
}

