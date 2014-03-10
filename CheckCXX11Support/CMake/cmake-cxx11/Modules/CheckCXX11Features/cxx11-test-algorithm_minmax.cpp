#include <vector>
#include <functional>
#include <algorithm>

int main()
{
  typedef std::vector<int> CollectionType;
  typedef CollectionType::iterator CollectionTypeIter;
  std::vector<int> a;
  a.push_back(9);
  a.push_back(7);
  a.push_back(5);
  a.push_back(3);
  a.push_back(1);
  a.push_back(2);
  a.push_back(4);
  a.push_back(6);
  a.push_back(8);
  a.push_back(10);

  std::pair<CollectionTypeIter,CollectionTypeIter> mm = std::minmax_element(a.begin(), a.end());

  bool aRes = (((*mm.first) == 1) && ((*mm.second) == 10));

  mm = std::minmax_element(a.begin(), a.end(), std::greater<int>());

  bool bRes = (((*mm.first) == 10) && ((*mm.second) == 1));

  
  return (aRes && bRes) ? 0 : 1;
}
