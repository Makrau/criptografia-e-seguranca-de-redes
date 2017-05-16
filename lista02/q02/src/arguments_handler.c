#include <stdio.h>
#include <string.h>

#include "arguments_handler.h"

int validate_arguments(int argc, char* argv[], des_config* config) {
	int valid_arguments = VALID_ARGUMENTS;
	if(argc < NUMBER_OF_ARGUMENTS) {
		invalid_number_of_arguments();
		return INVALID_ARGUMENTS;
	}

	get_algorithm_mode(argv, config, &valid_arguments);

	return valid_arguments;

}

void invalid_number_of_arguments() {
	printf("Wrong number of arguments.\n");
	printf("This program needs at least 3 arguments: \n");
	printf("1)Mode: -e to encrypt, -d to decrypt.\n");
	printf("2)The path to the input file.\n");
	printf("3)The path to the output file.\n");
	printf("\n");
	tips();
	
}

void tips() {
	printf("Notice that during encrypt the input file should be your plaintext, "); 
	printf("and the output file will be the correspondent ciphertext.\n");
	printf("But, during decryption, the input file must be the ciphertext, ");
	printf("and the output file will be the correspondent plaintext.\n");
	printf("The program will also search for a file called 'keyfile' to use as key.");
	printf("If the keyfile can't be found, the program will generate a key for you.");
	printf("One must use the same keyfile to encrypt and decrypt to get the algorithm");
	printf("to work properly.\n");
}

void get_algorithm_mode(char* argv[], des_config* config, int* valid_arguments) {
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
