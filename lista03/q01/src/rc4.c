#include "rc4.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* ksa(unsigned char* key) {
	unsigned int keylength = strlen((char*)key);
	unsigned char* S = malloc(256 * sizeof(char));
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned char aux;

	for(i = 0; i < 256; i++) {
		S[i] = i;
	}

	for(i = 0; i < 256; i++) {
		j = (j + S[i] + key[i % keylength]) % 256;
		aux = S[i];
		S[i] = S[j];
		S[j] = aux;
	}

	return S;
}

unsigned char* generate_keystream(int stream_size, unsigned char* key) {
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int current_iteration = 0;
	unsigned char aux;
	unsigned char* S = ksa(key);
	unsigned char* K = malloc(stream_size * sizeof(char));

	for(current_iteration = 0; current_iteration < stream_size; current_iteration++) {
		printf("iteration: %d\n", current_iteration);
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		aux = S[i];
		S[i] = S[j];
		S[j] = aux;
		K[current_iteration] = S[(S[i] + S[j]) % 256];
	}

	return K;
}
