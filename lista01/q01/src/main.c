#include <stdio.h>
#include <stdlib.h>


#include "des.h"

unsigned char main_key[8] = "amorvida";

int main(int argc, char* argv[]) {
	unsigned char* key_string;
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
	generate_sub_keys(key_string);

	free(key);
	free(key_string);

	return 0;
}

