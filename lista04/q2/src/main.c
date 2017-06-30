#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "argument_handler.h"

int main(int argc, char* argv[]) {
	config* config = malloc(sizeof(config));
	int valid_arguments = verify_arguments(argc, argv, config);

	if(valid_arguments == VALID) {
		printf("a: %d\n", config->a);
		printf("b: %d\n", config->b);
		printf("p: %d\n", config->p);
	}
	else {
		printf("Argumentos inválidos!\n");
	}
	return 0;
}