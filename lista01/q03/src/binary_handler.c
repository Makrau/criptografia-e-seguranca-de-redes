#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "binary_handler.h"

void usage(){
  printf("How to Use:\n"
      "Insert one number(0 <= x >= 255)\n"
      "The desired operation(+, -, /, *)\n"
      "And the second number(0 <= x >= 255)\n\n");
}

long decimal_binary(long n) {
  int rest;
  long bin = 0, i = 1;

  while(n != 0) {
    rest = n % 2;
    n = n/2;
    bin += (rest * i);
    i *= 10;
  }
  return bin;
}

long bin_decimal(long n) {
  int rest;
  long decimal = 0, i = 0;
  while(n != 0) {
    rest = n % 10;
    n /= 10;
    decimal += (rest * pow(2,i));
    ++i;
  }
  return decimal;
}

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

}
