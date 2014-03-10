#include <vector>
#include <iterator>

int main() 
{
  int input[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::vector<int> aPut(10);
  std::copy_n(input, 10, aPut.begin());
  bool aRes = ((aPut.at(0) == 0) && (aPut.at(9) == 9));

  std::vector<int> bPut(5);
  std::copy_n(input+2, 5, bPut.begin());
  bool bRes = ((bPut.at(0) == 2) && (bPut.at(4) == 6));
 
  return (aRes && bRes) ? 0 : 1;
}
