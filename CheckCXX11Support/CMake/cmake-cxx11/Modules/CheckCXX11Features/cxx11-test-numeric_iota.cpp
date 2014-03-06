#include <numeric>
#include <list>

int main()
{
  std::list<int> l(10);
  std::iota(l.begin(), l.end(), 0);
  bool res = ((l.front() == 0) &&
              (l.back() == 9) &&
              (std::accumulate(l.begin(), l.end(), 0) == 45));

  return res ? 0 : 1;
}

