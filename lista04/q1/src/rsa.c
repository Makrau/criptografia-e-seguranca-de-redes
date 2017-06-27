#include "rsa.h"
#include "config.h"
#include "mathematical_functions.h"
#include "file_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_rsa(unsigned char* message, config* config) {
	int n = (config->p) * (config->q);
	size_t message_lenght = strlen((char*)message);
	size_t i = 0;

	unsigned int* result = malloc((message_lenght * sizeof(int)) + sizeof(int));

	for(i = 0; i < message_lenght; i++) {
		result[i] = (unsigned int)modular_power(message[i], config->public_key, n);
	}
	result[i] = '\0';
	
	FILE* output_file = fopen(config->output_path, "wb");
	fwrite(result, sizeof(int), message_lenght, output_file);
}

void decrypt_rsa(unsigned int* ciphertext, config* config) {
	int n = (config->p) * (config->q);
	long unsigned int cipher_size = get_cipher_size(config->input_file);
	unsigned int i = 0;
	unsigned char* result = malloc((cipher_size * sizeof(char)) + sizeof(char));

	for(i = 0; i < cipher_size; i++) {
		result[i] = (unsigned char)modular_power((int)ciphertext[i], config->private_key, n);
	}

	result[i] = '\0';
	
	FILE* output_file = fopen(config->output_path, "wb");
	fwrite(result, sizeof(char), cipher_size, output_file);
}
