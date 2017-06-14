#include "libmiller_rabin.h"
#include <math.h>

void probability(int input_k){
  double p;
  p = pow(0.25, input_k);
  p *= 100;
  printf("With probability p~=%.2f%%\n", 100 - p);
}

int power(int x, unsigned int y, int p){
  int res = 1;
  x = x % p;

  while (y > 0){

    if (y & 1)
      res = (res * x) % p;

    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

int miller_rabin(int d, int n){
  int a, x;

  a = true_rand_number(n);

  x = power(a, d, n);

  if (x == 1  || x == n-1)
    return 1;

  while (d != n-1){
    x = (x * x) % n;
    d *= 2;

    if (x == 1)
      return 0;
    if (x == n-1)
      return 1;
  }

  return 0;
}

int is_prime(int n, int k){
  if (n <= 1 || n == 4)
    return 0;
  if (n <= 3)
    return 1;

  int d = n - 1;
  while (d % 2 == 0)
    d /= 2;

  for (int i = 0; i < k; i++){
    if (miller_rabin(d, n) == 0)
      return 0;
  }

  return 1;
}
