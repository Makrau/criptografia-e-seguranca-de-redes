#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "binary_handler.h"

void usage(){
  printf("How to Use:\n"
      "Insert two numbers(0 <= x >= 255)\n"
      "And the desired operation(+, -, /, *)\n\n");
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
