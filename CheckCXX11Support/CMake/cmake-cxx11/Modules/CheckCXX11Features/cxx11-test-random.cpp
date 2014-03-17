#include <random>

int main()
{
  std::default_random_engine gen;
  std::uniform_int_distribution<int> dist(1,6);
  int roll = dist(gen);

  return ((roll > 0) && (roll < 7)) ? 0 : 1;
}
