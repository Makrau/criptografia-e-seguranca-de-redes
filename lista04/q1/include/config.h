#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>

#define ENCRYPTION_MODE 0
#define DECRYPTION_MODE 1

typedef struct config {
	int p;
	int q;
	int public_key;
	int private_key;
	FILE* input_file;
	FILE* output_file;
	int algorithm_mode;
} config;
#endif