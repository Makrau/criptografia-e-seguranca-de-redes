#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>

#define ENCRYPTION_MODE 0
#define DECRYPTION_MODE 1

typedef struct {
	int algorithm_mode;
	FILE* input_file;
	FILE* output_file;
	int key_size;
} config;

#endif