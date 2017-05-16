#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "binary_handler.h"

unsigned char* translate_char_to_binary_string(char input) {
	int i;
	unsigned char* binary_string = (unsigned char*) malloc( 9 * sizeof(char));

	for (i=0; i<8; i++) {
		char shift_byte = 0x01 << (7-i);
		if (shift_byte & input) {
			binary_string[i] = '1';
		} else {
			binary_string[i] = '0';
		}
	}

	binary_string[8] = '\0';

	return binary_string;
}

unsigned int translate_binary_string_to_int(char* input) {
	unsigned int value = 0;
	int input_size = strlen(input);
	for(int i = 0; i<input_size; i++) {
		if(input[i] == '1') {
			value += pow(2, input_size - (i + 1));
		}
	}

	return value;
}

unsigned char* string_xor(unsigned char* word1, unsigned char* word2) {
	int word1_size = strlen((char*)word1);
	int word2_size = strlen((char*)word2);

	if(word1_size == word2_size) {
		unsigned char* final_string = malloc(word1_size * sizeof(char));

		for(int i = 0; i < word1_size; i++) {
			if(word1[i] != word2[i]) {
				final_string[i] = '1';
			}
			else {
				final_string[i] = '0';
			}
		}

		return final_string;
	}
	else {
		printf("Erro on string_xor. Strings of different sizes!\n");
		printf("Word1 size: %d\n", word1_size);
		printf("Word2 size: %d\n", word2_size);
		printf("Word1: %s\n", word1);
		printf("Word2: %s\n", word2);
		return NULL;
	}
}