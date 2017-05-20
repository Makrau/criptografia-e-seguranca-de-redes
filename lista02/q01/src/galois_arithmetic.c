#include "galois_arithmetic.h"

uint8_t gf_xor(uint8_t a, uint8_t b){
  uint8_t result;
  result= a ^ b;
  return result;
}

uint8_t gf_mult(uint8_t a, uint8_t b){
  uint8_t result = 0;
  while (b) {
    if (b & 1)
      result ^= a;
    if (a & 0x80)
      a = (a << 1) ^ 0x11b;
    else
      a <<= 1;
    b >>= 1;
  }
  return result;
}

uint8_t gf_div(uint8_t a, uint8_t b){
  uint8_t r = -1, mult;
  for (int i = 0; i <= 255; ++i) {
    mult = gf_mult(b, i);
    if((mult % 27) == 1){
      r = i;
      break;
    }
  }

  return gf_mult(a, r);
}
