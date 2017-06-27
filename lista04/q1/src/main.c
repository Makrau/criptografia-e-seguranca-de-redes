#include <stdio.h>
#include <stdlib.h>

#include "argument_handler.h"
#include "config.h"

int main(int argc, char* argv[]) {
	config* config = malloc(sizeof(config));
	int valid_arguments = verify_arguments(argc, argv, config);

	if(valid_arguments == VALID) {
		get_private_key(config);
	}
	else{
		printf("tá tudo errado...\n");
	}
	
	return 0;
}