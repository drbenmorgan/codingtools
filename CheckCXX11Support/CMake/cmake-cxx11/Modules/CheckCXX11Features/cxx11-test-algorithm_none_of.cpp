#include <vector>
#include <algorithm>

bool isNegative(int x) {
  return x < 0;
}

int main()
{
  std::vector<int> a;
  a.push_back(2);
  a.push_back(4);
  a.push_back(6);
  a.push_back(8);

  bool aRes = std::none_of(a.begin(), a.end(), isNegative);

  std::vector<int> b;
  b.push_back(2);
  b.push_back(4);
  b.push_back(-3);
  b.push_back(6);

  bool bRes = std::none_of(b.begin(), b.end(), isNegative);
  
  return (aRes && !bRes) ? 0 : 1;
}

