#include <stdio.h>
#include <stdlib.h>

#include "argument_handler.h"
#include "config.h"
#include "rsa.h"
#include "file_handler.h"

int main(int argc, char* argv[]) {
	config* config = malloc(sizeof(config));
	int valid_arguments = verify_arguments(argc, argv, config);
	char* message;
	unsigned int* ciphertext;

	if(valid_arguments == VALID) {
		get_additional_data(config);
		if(config->algorithm_mode == ENCRYPTION_MODE) {
			message = read_text_file(config->input_file);
			encrypt_rsa(message, config);
		}
		else {
			ciphertext = read_ciphertext(config->input_file);
			
		}
	}
	else{
		printf("tá tudo errado...\n");
	}
	
	return 0;
}