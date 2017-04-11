#include <stdlib.h>
#include <stdio.h>

#include "binary_handler.h"

unsigned char* translate_char_to_binary(char input) {
	int i;
	unsigned char* binary_string = (unsigned char*) malloc( 8 * sizeof(char));

	for (i=0; i<8; i++) {
		char shift_byte = 0x01 << (7-i);
		if (shift_byte & input) {
			binary_string[i] = '1';
		} else {
			binary_string[i] = '0';
		}
	}
	printf("impressão intermediaria: %s\n", binary_string);

	return binary_string;
}