#include <stdio.h>
#include <stdlib.h>

#include "argument_handler.h"
#include "config.h"
#include "rsa.h"

int main(int argc, char* argv[]) {
	config* config = malloc(sizeof(config));
	int valid_arguments = verify_arguments(argc, argv, config);
	char* message;

	if(valid_arguments == VALID) {
		get_additional_data(config);
	}
	else{
		printf("tá tudo errado...\n");
	}
	
	return 0;
}