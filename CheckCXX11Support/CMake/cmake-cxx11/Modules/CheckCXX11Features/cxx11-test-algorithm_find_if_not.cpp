#include <vector>
#include <algorithm>

bool isOdd(int i) {
  return (i % 2);
}

int main()
{
  std::vector<int> a;
  a.push_back(1);
  a.push_back(3);
  a.push_back(5);
  a.push_back(7);
  a.push_back(9);

  bool aRes = (std::find_if_not(a.begin(), a.end(), isOdd) == a.end());
  
  std::vector<int> b;
  b.push_back(1);
  b.push_back(3);
  b.push_back(5);
  b.push_back(6);
  b.push_back(7);

  bool bRes = (*(std::find_if_not(b.begin(), b.end(), isOdd)) == 6); 
  
  return (aRes && bRes) ? 0 : 1;
}
