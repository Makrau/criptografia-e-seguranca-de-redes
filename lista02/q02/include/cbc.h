#ifndef CBC_H
#define CBC_H

#include "config.h"

#define DES_KEY_BYTE_SIZE 8

unsigned char* process_first_block(unsigned char* first_block_message);
void run_cbc(config* config);
unsigned char* read_key();

#endif