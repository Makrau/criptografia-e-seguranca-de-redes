#include <stdio.h>

#include "arguments_handler.h"

#define ARGUMENTS_OK 0
#define ARGUMENTS_NOT_OK 1
#define NUMBER_OF_ARGUMENTS 5
#define ENCRYPTION_MODE_ARGUMENT_POSITON 1
#define AES_KEY_SIZE_MODE_ARGUMENT_POSITION 2
#define INPUT_FILE_ARGUMENT_POSITION 3
#define OUTPUT_FILE_ARGUMENT_POSITION 4

int validate_arguments(int argc, char* argv[]) {
	
	if(argc < NUMBER_OF_ARGUMENTS) {
		invalid_number_of_arguments();
		return ARGUMENTS_NOT_OK;
	}

	return ARGUMENTS_OK;

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