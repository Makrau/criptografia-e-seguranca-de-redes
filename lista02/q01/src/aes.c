#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "aes.h"

unsigned char* generate_key() {
	int i;
	unsigned char* key = (unsigned char*) malloc(AES128_KEY_BYTE_SIZE * sizeof(char));
	FILE* key_file = fopen("keyfile", "wb");

	unsigned int seed = (unsigned int)time(NULL);
	srand (seed);

	if (!key_file) {
		printf("Problems opening the keyfile");
		return NULL;
	}

	for (i=0; i<8; i++) {
		key[i] = rand()%255;
	}


	fwrite(key, 1, AES128_KEY_BYTE_SIZE, key_file);
	fclose(key_file);

	return key;
}