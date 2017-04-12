#ifndef _DES_H_
#define _DES_H_

#define ENCRYPTION_MODE 1
#define DECRYPTION_MODE 0
#define KEY_SIZE 8
#define BYTE_SIZE 8
#define PERMUTED_KEY_SIZE 56
#define KEY_C_D_AMOUNT 17
#define C_D_SIZE 28
#define FIRST_SUB_KEY 1

typedef struct {
	unsigned char key[PERMUTED_KEY_SIZE];
	unsigned char c[C_D_SIZE];
	unsigned char d[C_D_SIZE];
} key_structure;

unsigned char* generate_key();
unsigned char* generate_binary_key_string(unsigned char* key);
unsigned char* pc1_function(unsigned char* key_string);
key_structure* generate_sub_keys(unsigned char* key_string);

#endif