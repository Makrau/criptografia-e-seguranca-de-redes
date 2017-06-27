#include "file_handler.h"

#include <stdlib.h>
#include <stdio.h>

char* read_text_file(FILE* file) {
	char* message = NULL;
	char* aux_pointer = NULL;
	size_t string_size = 0;
	size_t position = 0;
	int read_char = EOF;

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
		message[position] = (char)read_char;
		position++;
	}

	return message;
}

unsigned int* read_ciphertext(FILE* file) {
	unsigned int* ciphertext = NULL;
	unsigned int* aux_pointer = NULL;
	size_t string_size = 0;
	size_t position = 0;
	unsigned int read_number = 1;

	while(read_number) {
		fread(&read_number, sizeof(int), 1, file);
		printf("readed: %d\n", read_number);

		if(read_number == '\n' || read_number == '\0') {
			ciphertext[position] = '\0';
			return ciphertext;
		}

		if(string_size <= position) {
			string_size++;
			aux_pointer = realloc(ciphertext, string_size);

			if(!aux_pointer) {
				printf("Error on realloc!\n");
				free(ciphertext);
				return NULL;
			}

			ciphertext = aux_pointer;
		}
		ciphertext[position] = read_number;
		position++;
	}

	return ciphertext;
}

void clear_buffer() {
	int c;
	while((c = fgetc(stdin)) != '\n' && c != EOF);
	return;
}