#include <functional>

struct IntMultiplier {
  int value;

  int byTwo() {
    return value*2;
  }

  int byThree() {
    return value*3;
  }

  int byFactor(int f) {
    return value*f;
  }
};


int main()
{
  std::function<int(IntMultiplier)> doubler = std::mem_fn(&IntMultiplier::byTwo);
  std::function<int(IntMultiplier)> tripler = std::mem_fn(&IntMultiplier::byThree);
  std::function<int(IntMultiplier, int)> factor = std::mem_fn(&IntMultiplier::byFactor); 
  
  IntMultiplier foo = {5};
  
  return ((doubler(foo) == 10) &&
          (tripler(foo) == 15) &&
          (factor(foo,2) == 10)) ? 0 : 1;
}
