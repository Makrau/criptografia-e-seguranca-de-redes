#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>

#define ENCRYPTION_MODE 1
#define DECRYPTION_MODE 2

typedef struct config {
	int p;
	int q;
	int public_key;
	int private_key;
	FILE* input_file;
	char* output_path;
	int algorithm_mode;
} config;

void get_additional_data(config* config);
void get_private_key(config* config);
void get_algorithm_mode(config* config);
void get_input_path(config* config);
void print_algorithm_modes();

#endif