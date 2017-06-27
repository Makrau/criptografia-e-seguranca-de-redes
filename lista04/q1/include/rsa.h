#ifndef RSA_H
#define RSA_H

#include "config.h"

void encrypt_rsa(unsigned char* message, config* config);
void decrypt_rsa(unsigned int* ciphertext, config* config);

#endif