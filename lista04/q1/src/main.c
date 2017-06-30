#include <stdio.h>
#include <stdlib.h>

#include "argument_handler.h"
#include "config.h"
#include "rsa.h"
#include "file_handler.h"

int main(int argc, char* argv[]) {
	config* config = malloc(sizeof(config));
	int valid_arguments = verify_arguments(argc, argv, config);
	int valid_data;
	unsigned char* message;
	unsigned int* ciphertext;

	if(valid_arguments == VALID) {
		valid_data = get_additional_data(config);
		if(!valid_data) {
			printf("Erro nos dados informados. Encerrando programa...\n");
			return 0;
		}
		if(config->algorithm_mode == ENCRYPTION_MODE) {
			message = read_text_file(config->input_file);
			encrypt_rsa(message, config);
			free(message);
		}
		else {
			ciphertext = read_ciphertext(config->input_file);
			decrypt_rsa(ciphertext, config);
			free(ciphertext);
		}
	}
	else{
		printf("Erro nos argumentos.\nFechando programa....\n");
	}
	
	return 0;
}