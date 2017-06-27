#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>

typedef struct config {
	int p;
	int q;
	int public_key;
	int private_key;
	FILE* input_file;
	FILE* output_file;
} config;
#endif