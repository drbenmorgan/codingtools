#include <cmath>
#include <fenv.h>

int main()
{
  bool hasHyperbolic = (std::acosh(1.1) > 0.0) &&
                       (std::asinh(1.1) > 0.0) &&
                       (std::atanh(0.9) > 0.0);

  bool hasExpLog = (std::exp2(1.0) > 0.0) &&
                   (std::expm1(1.0) > 1.0) &&
                   (std::ilogb(10.0) > 0.0) &&
                   (std::log1p(1.0) > 0.0) &&
                   (std::log2(4.0) > 1.0) &&
                   (std::logb(10.0) > 0.0) &&
                   (std::scalbn(1.0,1) > 0.0) &&
                   (std::scalbln(1.0,1) > 0.0);

  bool hasPower = (std::cbrt(8.0) > 0.0) && (std::hypot(3.0,4.0) > 4.0);

  bool hasErrGamma = (std::erf(1.0) > 0.0) &&
                     (std::erfc(1.0) < 1.0) &&
                     (std::tgamma(0.5) > 0.0) &&
                     (std::lgamma(0.5) > 0.0);

  bool hasRound = (std::trunc(2.5) < 2.5) &&
                  (std::round(2.5) > 2.5) && 
                  (std::lround(2.4) < 2.4) &&
                  (std::lround(2.6) > 2.6) &&
                  (std::llround(2.4) == 2) &&
                  (std::llround(2.6) == 3);
 
  bool hasRoundFEnv(false);
  switch (fegetround()) {
    case FE_DOWNWARD:
      hasRoundFEnv = (std::rint(2.8) < 2.8) &&
                     (std::lrint(2.8) == 2) &&
                     (std::llrint(2.8) == 2) &&
                     (std::nearbyint(2.8) < 2.8);
      break;
    case FE_TONEAREST:
      hasRoundFEnv = (std::rint(2.8) > 2.8) &&
                     (std::lrint(2.8) == 3) &&
                     (std::llrint(2.8) == 3) &&
                     (std::nearbyint(2.8) > 2.8);
      break;
    case FE_TOWARDZERO:
      hasRoundFEnv = (std::rint(2.8) < 2.8) &&
                     (std::lrint(2.8) == 2) &&
                     (std::llrint(2.8) == 2) &&
                     (std::nearbyint(2.8) < 2.8);
      break;
    case FE_UPWARD:
      hasRoundFEnv = (std::rint(2.4) > 2.4) &&
                     (std::lrint(2.4) == 3) &&
                     (std::llrint(2.4) == 3) &&
                     (std::nearbyint(2.4) > 2.4);
      break;
    default:
      hasRoundFEnv = false;
  }

  int quo(0);
  double remQuoResult = std::remquo(10.3, 4.5, &quo);
  bool hasRemainder = (std::remainder(18.5, 4.2) > 1.6) &&
                      (remQuoResult > 1.2) &&
                      (quo == 2);

  bool hasFMA = (std::fma(10.0, 20.0, 30.0) > 0.0);

  return (hasHyperbolic && hasExpLog && hasPower && hasErrGamma && hasRound && hasRoundFEnv && hasRemainder && hasFMA) ? 0 : 1;
}

