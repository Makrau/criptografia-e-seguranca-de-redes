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

	if(valid_arguments == VALID) {
		get_additional_data(config);
		message = read_file(config->input_file);
		printf("Mensagem: %s\n", message);
	}
	else{
		printf("tá tudo errado...\n");
	}
	
	return 0;
}