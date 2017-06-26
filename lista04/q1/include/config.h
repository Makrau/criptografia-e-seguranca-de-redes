#ifndef CONFIG_H
#define CONFIG_H

typedef struct config {
	int n;
	int public_key;
	int private_key;
	FILE* input_file;
	FILE* output_file;
} config;
#endif