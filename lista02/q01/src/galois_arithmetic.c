#include "galois_arithmetic.h"

long gf_xor(long a, long b){
  long result;
  result= a ^ b;
  return result;
}

long gf_mult(long a, long b){
  long result = 0;
  while (b) {
    if (b & 1)
      result ^= a;
    if (a & 128)
      a = (a << 1) ^ 283;
    else
      a <<= 1;
    b >>= 1;
  }
  return result;
}

long gf_div(long a, long b){
  long r = -1, mult;
  for (int i = 0; i <= 256; ++i) {
    mult = gf_mult(b, i);
    if((mult % 27) == 1){
      r = i;
      break;
    }
  }

  return gf_mult(a, r);
}
