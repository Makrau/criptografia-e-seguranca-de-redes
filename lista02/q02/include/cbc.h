#ifndef CBC_H
#define CBC_H

#include "config.h"

#define DES_KEY_BYTE_SIZE 8
#define DES_BLOCK_BYTE_SIZE 8

unsigned char* cbc_pre_process(unsigned char* message, unsigned char* previous_ciphertext);
void run_cbc(config* config);
unsigned char *append_plaintext(unsigned char* plaintext);
unsigned char* read_key();

#endif