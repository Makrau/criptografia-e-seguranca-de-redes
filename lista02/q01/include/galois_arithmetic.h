#ifndef GALOIS_ARITHMETIC_H
#define GALOIS_ARITHMETIC_H

#include <stdint.h>

uint8_t gf_xor(uint8_t a, uint8_t b);
uint8_t gf_mult(uint8_t a, uint8_t b);
uint8_t gf_div(uint8_t a, uint8_t b);

#endif
