#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_handler.h"
#include "des.h"

int main(int argc, char* argv[]) {
	unsigned char* key_string;
	unsigned char* message_binary_string;
	unsigned char* key = malloc(8 * sizeof(char));
	unsigned char* message = malloc(8 * sizeof(char));
	key_structure* sub_keys;
	FILE* key_file = fopen("keyfile", "rb");
	FILE* input_file;
	FILE* output_file;
	int mode;

	if(argc < 4) {
		printf("inform the mode, input file and output file\n");
		printf("Modes: -e (encrypt) | -d (decrypt)\n");
		return 1;
	}
	else {
		input_file = fopen(argv[2], "rb");
		output_file = fopen(argv[3], "wb");
		if(strcmp(argv[1], "-e") == 0) {
			mode = ENCRYPT_MODE;
		}
		else if(strcmp(argv[1], "-d") == 0) {
			mode = DECRYPT_MODE;
		}
		else {
			printf("wrong mode. -e to encrypt or -d to decrypt");
			return 1;
		}
	}

	if(key_file) {
		fread(key, sizeof(char), KEY_CHAR_SIZE, key_file);
		fclose(key_file);
	}
	else {
		printf("chave não encontrada.\n");
		printf("Gerando chave...\n");
		key = generate_key();
	}

	if(input_file){
		fread(message, sizeof(char), 8, input_file);
		fclose(input_file);
	}
	else {
		printf("input file not found.\n");
		return 1;
	}

	printf("message: %s\n", message);
	
	printf("gerando string da chave: \n");
	key_string = generate_binary_key_string(key);
	printf("\ngerando string da mensagem \n");
	message_binary_string = generate_binary_message_string(message);

	sub_keys = generate_sub_keys(key_string);

	if(mode == ENCRYPT_MODE) {
		printf("M: %s\n", message_binary_string);
		unsigned char* crypted_message;
		crypted_message = encrypt_message(message_binary_string, sub_keys);
		fwrite(crypted_message, 1, 8, output_file);
		fclose(output_file);
	}
	else {
		decrypt_message(message_binary_string, sub_keys);
	}

	char caractere[8];

	strncpy(caractere, (char*)sub_keys[16].key, 8);

	printf("caractere: %s\n", caractere);

	int value = translate_binary_string_to_int(caractere);

	printf("value: %d\n", value);

	free(key);
	free(key_string);
	free(message_binary_string);
	free(sub_keys);

	return 0;
}

