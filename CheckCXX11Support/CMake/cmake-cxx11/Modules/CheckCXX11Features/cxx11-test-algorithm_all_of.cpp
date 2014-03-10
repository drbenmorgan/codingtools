#include <vector>
#include <algorithm>

bool isPositive(int x) {
  return (x > 0);
}

int main()
{
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_back(5);

  bool aRes = std::all_of(a.begin(), a.end(), isPositive);

  std::vector<int> b;
  b.push_back(1);
  b.push_back(2);
  b.push_back(3);
  b.push_back(-4);
  b.push_back(5);

  bool bRes = std::all_of(b.begin(), b.end(), isPositive);

  return (aRes && !bRes) ? 0 : 1;
}

