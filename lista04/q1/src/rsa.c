#include "rsa.h"
#include "config.h"
#include "mathematical_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_rsa(char* message, config* config) {
	int n = (config->p) * (config->q);
	size_t message_lenght = strlen((char*)message);
	size_t i = 0;

	for(i = 0; i < message_lenght; i++) {
	}

	unsigned int* result = malloc((message_lenght * sizeof(int)) + sizeof(int));
	printf("Tamanho da mensagem: %lu\n", message_lenght);

	for(i = 0; i < message_lenght; i++) {
		result[i] = (unsigned int)modular_power(message[i], config->public_key, n);
	}
	result[i] = '\0';
	for(i = 0; i < message_lenght; i++) {
		printf("Result: %d\n", result[i]);
	}
	
	
	FILE* output_file = fopen(config->output_path, "wb");
	fwrite(result, sizeof(int), message_lenght, output_file);
}

