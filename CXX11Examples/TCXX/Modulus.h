//! \file TCXX/Modulus.h
//! \brief Modular arithmetic operation

#ifndef TCXX_MODULUS_HH
#define TCXX_MODULUS_HH

namespace tcxx {
int modulo(int value, int modulus) {
  int remainder(value % modulus);
  if (value < 0) {
    remainder += modulus;
  }
  return remainder;
}
} // namespace tcxx

#endif // TCXX_MODULUS_HH

