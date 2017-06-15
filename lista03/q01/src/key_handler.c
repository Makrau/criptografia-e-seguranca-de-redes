#include "key_handler.h"

#include <stdlib.h>
#include <stdio.h>

unsigned char* read_key(FILE* keyfile) {
	unsigned char* key = NULL;
	unsigned char* aux_pointer = NULL;
	size_t string_size = 0;
	size_t position = 0;
	unsigned char read_char = EOF;

	while(read_char) {
		printf("reading key. Position: %d\n", (int)position);
		read_char = getc(keyfile);
		printf("readed char: %c\n", read_char);
		printf("current key: %s\n", key);

		if(read_char == EOF || read_char == '\n' || read_char == '\0') {
			key[position] = '\0';
			printf("Entrou no if!!!!\n");
			return key;
		}

		if(string_size <= position) {
			string_size++;
			aux_pointer = realloc(key, string_size);

			if(!aux_pointer) {
				printf("Error on realloc!\n");
				free(key);
				return NULL;
			}

			key = aux_pointer;
		}
		key[position] = read_char;
		position++;
	}

	return key;
}