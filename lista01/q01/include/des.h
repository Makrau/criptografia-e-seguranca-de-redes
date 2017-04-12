#ifndef _DES_H_
#define _DES_H_

#define ENCRYPTION_MODE 1
#define DECRYPTION_MODE 0
#define KEY_SIZE 8
#define BYTE_SIZE 8
#define PERMUTED_KEY_SIZE 56

typedef struct {
	unsigned char key[8];
	unsigned char c[4];
	unsigned char d[4];
} key_structure;

unsigned char* generate_key();
unsigned char* generate_binary_key_string(unsigned char* key);
unsigned char* pc1_function(unsigned char* key_string);

#endif