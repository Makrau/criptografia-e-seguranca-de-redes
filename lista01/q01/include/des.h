#ifndef _DES_H_
#define _DES_H_

#define ENCRYPTION_MODE 1
#define DECRYPTION_MODE 0
#define KEY_CHAR_SIZE 8
#define BYTE_SIZE 8
#define PC1_SIZE 56
#define KEY_BIT_SIZE 48
#define KEY_C_D_AMOUNT 17
#define C_D_SIZE 28
#define FIRST_SUB_KEY 1

typedef struct {
	unsigned char key[KEY_BIT_SIZE + 1];
	unsigned char c[C_D_SIZE + 1];
	unsigned char d[C_D_SIZE + 1];
} key_structure;

unsigned char* generate_key();
unsigned char* generate_binary_key_string(unsigned char* key);
unsigned char* pc1_function(unsigned char* key_string);
key_structure* generate_sub_keys(unsigned char* key_string);
void make_rounds(key_structure* sub_keys, int round);

#endif