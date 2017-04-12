#include <stdio.h>
#include <stdlib.h>


#include "des.h"

int ip[] = {58, 50, 42, 34, 26, 18, 10, 2,
						60, 52, 44, 36, 28, 20, 12, 4,
						62, 54, 46, 38, 30, 22, 14, 6,
						64, 56, 48, 40, 32, 24, 16, 8,
						57, 49, 41, 33, 25, 17,  9, 1,
						59, 51, 43, 35, 27, 19, 11, 3,
						61, 53, 45, 37, 29, 21, 13, 5,
						63, 55, 47, 39, 31, 23, 15, 7};

int ip_1[] =   {40,  8, 48, 16, 56, 24, 64, 32,
											39,  7, 47, 15, 55, 23, 63, 31,
											38,  6, 46, 14, 54, 22, 62, 30,
											37,  5, 45, 13, 53, 21, 61, 29,
											36,  4, 44, 12, 52, 20, 60, 28,
											35,  3, 43, 11, 51, 19, 59, 27,
											34,  2, 42, 10, 50, 18, 58, 26,
											33,  1, 41,  9, 49, 17, 57, 25};

unsigned char main_key[8] = "amorvida";

int main(int argc, char* argv[]) {
	unsigned char* key_string;
	unsigned char* permuted_key_string;
	unsigned char* key = malloc(8 * sizeof(char));
	FILE* key_file = fopen("keyfile", "rb");
	if(key_file) {
		fread(key, sizeof(char), KEY_SIZE, key_file);
		fclose(key_file);
	}
	else {
		printf("chave não encontrada.\n");
		printf("Gerando chave...\n");
		key = generate_key();
	}
	
	key_string = generate_binary_key_string(key);
	permuted_key_string = pc1_function(key_string);
	return 0;
}

