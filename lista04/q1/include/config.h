#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>

#define INVALID 0
#define VALID 1
#define ENCRYPTION_MODE 1
#define DECRYPTION_MODE 2
#define MIN_N 256

typedef struct config {
	int p;
	int q;
	int public_key;
	int private_key;
	FILE* input_file;
	char* output_path;
	int algorithm_mode;
} config;

int get_additional_data(config* config);
int get_private_key(config* config);
int get_algorithm_mode(config* config);
int get_input_path(config* config);
void print_algorithm_modes();

#endif