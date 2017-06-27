#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>

unsigned char* read_text_file(FILE* file);
void clear_buffer();
unsigned int* read_ciphertext(FILE* file);
long unsigned int get_cipher_size(FILE* ciphertext);

#endif