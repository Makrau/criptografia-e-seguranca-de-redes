#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "key_handler.h"
#include "binary_handler.h"

unsigned char* generate_key(int key_byte_size) {
	int i;
	unsigned char* key = (unsigned char*) malloc(key_byte_size * sizeof(char));
	FILE* key_file = fopen("keyfile", "wb");

	unsigned int seed = (unsigned int)time(NULL);
	srand (seed);

	if (!key_file) {
		printf("Problems opening the keyfile");
		return NULL;
	}

	for (i=0; i<key_byte_size; i++) {
		key[i] = rand()%255;
	}


	fwrite(key, 1, key_byte_size, key_file);
	fclose(key_file);

	return key;
}

unsigned char* generate_binary_key_string(unsigned char* key) {
	int key_size = strlen((char*)key);
	int binary_key_string_size;
	unsigned char* binary_key_string = (unsigned char*)
		malloc(key_size * BYTE_SIZE * sizeof(char) + 1);
	unsigned char* binary_char_string;

	for(int i = 0; i < key_size; i++) {
		binary_char_string = translate_char_to_binary_string(key[i]);
		if(i == 0) {
			strcpy((char*) binary_key_string, (char*) binary_char_string);
		}
		else{
			strncat((char*) binary_key_string, (char*) binary_char_string, BYTE_SIZE);
		}
	}

	binary_key_string_size = strlen((char*)binary_key_string);

	binary_key_string[binary_key_string_size] = '\0';

	return binary_key_string;
}