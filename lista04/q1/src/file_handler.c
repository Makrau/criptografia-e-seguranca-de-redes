#include "file_handler.h"

#include <stdlib.h>
#include <stdio.h>

unsigned char* read_text_file(FILE* file) {
	unsigned char* message = NULL;
	unsigned char* aux_pointer = NULL;
	size_t string_size = 0;
	size_t position = 0;
	unsigned int read_char = 1;

	while(read_char) {
		read_char = (unsigned)getc(file);

		if(read_char == '\n' || read_char == '\0') {
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
		message[position] = (unsigned char)read_char;
		position++;
	}

	return message;
}

unsigned int* read_ciphertext(FILE* file) {
	long unsigned int number_of_elements = get_cipher_size(file);
	unsigned int* ciphertext = malloc(number_of_elements* (sizeof(unsigned int)));
	size_t position = 0;
	unsigned int read_number = 1;

	while(position < number_of_elements) {
		fread(&read_number, sizeof(int), 1, file);

		if(read_number == '\0') {
			ciphertext[position] = '\0';
			return ciphertext;
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

long unsigned int get_cipher_size(FILE* file) {
	fseek(file, 0L, SEEK_END);
	long int file_size = ftell(file);
	long unsigned int number_of_elements = (long unsigned int)file_size / sizeof(int);
	rewind(file);

	return number_of_elements;
}