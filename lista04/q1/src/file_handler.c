#include "file_handler.h"

#include <stdlib.h>
#include <stdio.h>

unsigned char* read_file(FILE* file) {
	unsigned char* message = NULL;
	unsigned char* aux_pointer = NULL;
	size_t string_size = 0;
	size_t position = 0;
	unsigned char read_char = EOF;

	while(read_char) {
		read_char = getc(file);

		if(read_char == EOF || read_char == '\n' || read_char == '\0') {
			message[position] = '\0';
			return message;
		}

		if(string_size <= position) {
			string_size++;
			aux_pointer = realloc(message, string_size);

			if(!aux_pointer) {
				printf("Error on realloc!\n");
				free(message);
				return NULL;
			}

			message = aux_pointer;
		}
		message[position] = read_char;
		position++;
	}

	return message;
}