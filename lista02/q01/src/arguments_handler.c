#include <stdio.h>
#include <string.h>

#include "arguments_handler.h"

int validate_arguments(int argc, char* argv[], config* config) {
	int valid_arguments = VALID_ARGUMENTS;
	if(argc < NUMBER_OF_ARGUMENTS) {
		invalid_number_of_arguments();
		return INVALID_ARGUMENTS;
	}

	get_algorithm_mode(argv, config, &valid_arguments);
	get_key_size(argv, config, &valid_arguments);

	return valid_arguments;

}

void invalid_number_of_arguments() {
	printf("Wrong number of arguments.\n");
	printf("This program needs at least 4 arguments: \n");
	printf("1)Mode: -e to encrypt, -d to decrypt.\n");
	printf("2)Key size mode: can be 128, 192 and 256.\n");
	printf("3)The path to the input file.\n");
	printf("4)The path to the output file.\n");
	printf("\n");
	tips();
	
}

void tips() {
	printf("Notice that during encrypt the input file should be your plaintext, "); 
	printf("and the output file will be the correspondent ciphertext.\n");
	printf("But, during decryption, the input file must be the ciphertext, ");
	printf("and the output file will be the correspondent plaintext.\n");
	printf("The program will also search for a file called 'keyfile' to use as key.");
	printf("If the keyfile can't be found, the program will generate a key for you with ");
	printf("size correspondent to the key size mode argument (the second argument)\n");
	printf("One must use the same keyfile to encrypt and decrypt to get the algorithm");
	printf("to work properly.\n");
}

void get_algorithm_mode(char* argv[], config* config, int* valid_arguments) {
	int encryption_mode;
	int decryption_mode;
	char* argument_mode = argv[ENCRYPTION_MODE_ARGUMENT_POSITON];

	encryption_mode = strcmp("-d", argument_mode);
	decryption_mode = strcmp("-e", argument_mode);

	if(encryption_mode == 0) {
		config->algorithm_mode = ENCRYPTION_MODE;
	}
	else if(decryption_mode == 0) {
		config->algorithm_mode = DECRYPTION_MODE;
	}
	else {
		printf("Invalid algorithm mode. Use -e to encrypt or -d to decrypt.\n");
		*valid_arguments = INVALID_ARGUMENTS;
	}
}

void get_key_size(char* argv[], config* config, int* valid_arguments) {
	int aes128;
	int aes192;
	int aes256;

	aes128 = strcmp("128", argv[AES_KEY_SIZE_MODE_ARGUMENT_POSITION]);
	aes192 = strcmp("192", argv[AES_KEY_SIZE_MODE_ARGUMENT_POSITION]);
	aes256 = strcmp("256", argv[AES_KEY_SIZE_MODE_ARGUMENT_POSITION]);

	if(aes128 == 0) {
		config->key_size = 128;
	}
	else if(aes192 == 0) {
		config->key_size = 192;
	}
	else if(aes256 == 0) {
		config->key_size = 256;
	}
	else {
		printf("Invalid key size. Key size must be 128, 192 or 256.\n");
		*valid_arguments = INVALID_ARGUMENTS;
	}
}
