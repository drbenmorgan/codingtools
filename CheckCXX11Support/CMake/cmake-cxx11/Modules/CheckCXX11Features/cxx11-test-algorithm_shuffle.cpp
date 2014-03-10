#include <vector>
#include <algorithm>
// ? shuffle implementation requires <random>?
#include <random>

int main()
{
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(5);
 
  std::shuffle(a.begin(), a.end(), std::default_random_engine()); 
  
  return ((a.size() == 4) && 
          (std::accumulate(a.begin(), a.end(),0) == 11)) ? 0 : 1;
}

