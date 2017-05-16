#ifndef AES_H
#define AES_H

#define INPUT_BYTE_SIZE 16
#define AES128_KEY_BYTE_SIZE 16
#define AES192_KEY_BYTE_SIZE 24
#define AES256_KEY_BYTE_SIZE 32
#define ENCRYPTION_MODE 0
#define DECRYPTION_MODE 1

unsigned char* generate_key();

typedef struct aes_config{
	int algorithm_mode;
	int key_size;
} aes_config;

#endif