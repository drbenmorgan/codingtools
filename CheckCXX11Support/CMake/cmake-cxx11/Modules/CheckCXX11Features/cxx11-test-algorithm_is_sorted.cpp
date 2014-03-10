#include <vector>
#include <functional>
#include <algorithm>

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

  bool aRes = std::is_sorted(a.begin(), a.end());
  
  std::vector<int> b;
  b.push_back(10);
  b.push_back(9);
  b.push_back(8);
  b.push_back(7);
  b.push_back(6);
  b.push_back(5);
  b.push_back(4);
  b.push_back(3);
  b.push_back(2);
  b.push_back(1);

  bool bRes = std::is_sorted(b.begin(), b.end());
  bool cRes = std::is_sorted(b.begin(), b.end(), std::greater<int>());

  return (aRes && !bRes && cRes) ? 0 : 1;
}
