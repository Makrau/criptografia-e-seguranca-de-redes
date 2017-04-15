#include <stdio.h>
#include <stdlib.h>


#include "des.h"

unsigned char main_key[8] = "amorvida";

int main(int argc, char* argv[]) {
	unsigned char* key_string;
	unsigned char* key = malloc(8 * sizeof(char));
	key_structure* sub_keys;
	FILE* key_file = fopen("keyfile", "rb");
	if(key_file) {
		fread(key, sizeof(char), KEY_CHAR_SIZE, key_file);
		fclose(key_file);
	}
	else {
		printf("chave não encontrada.\n");
		printf("Gerando chave...\n");
		key = generate_key();
	}
	
	key_string = generate_binary_key_string(key);
	sub_keys = generate_sub_keys(key_string);

	for(int i = 1; i < 17; i++) {
		printf("C%d: %s\n",i, sub_keys[i].c);
		printf("D%d: %s\n",i, sub_keys[i].d);
		printf("K%d: %s\n",i, sub_keys[i].key);
		printf("\n");
	}

	free(key);
	free(key_string);
	free(sub_keys);

	return 0;
}

