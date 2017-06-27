#include "rsa.h"
#include "config.h"
#include "mathematical_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_rsa(char* message, config* config) {
	int n = (config->p) * (config->q);
	int message_lenght = strlen((char*)message);
	int i = 0;

	for(i = 0; i < message_lenght; i++) {
		printf("M: %d\n", message[i]);
	}

	unsigned int* result = malloc(message_lenght * sizeof(int));
	printf("Tamanho da mensagem: %d\n", message_lenght);

	for(i = 0; i < message_lenght; i++) {
		result[i] = (unsigned int)modular_power(message[i], config->public_key, n);
		printf("Result: %d\n", result[i]);
	}
	config-> output_file = fopen("output_file", "wb");
	fwrite(result, sizeof(int), message_lenght, config->output_file);
}

