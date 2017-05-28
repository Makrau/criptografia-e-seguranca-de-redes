#ifndef LIBMILLER_RABIN_H
#define LIBMILLER_RABIN_H

#include "libtruerand.h"

int power(int x, unsigned int y, int p);

int miller_rabin(int d, int n);

int is_prime(int n, int k);

#endif
