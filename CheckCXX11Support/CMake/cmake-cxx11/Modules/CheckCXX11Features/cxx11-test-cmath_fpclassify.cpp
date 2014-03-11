#include <cmath>

int main()
{
  return ((std::fpclassify(1.0) == FP_NORMAL) &&
         std::isfinite(1.0) &&
         std::isinf(INFINITY) &&
         std::isnan(NAN) &&
         std::isnormal(1.0) &&
         std::signbit(-1.0) &&
         std::isgreater(1.1, 1.0) &&
         std::isless(1.0, 1.1) &&
         std::isunordered(NAN, 1.0f)) ? 0 : 1;
}
