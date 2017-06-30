#include "argument_handler.h"

#include <stdlib.h>
#include <stdio.h>

int verify_arguments(int argc, char* argv[], config* config) {
	int valid = INVALID;

	if(argc < MIN_ARGUMENTS) {
		print_arguments_message();
		return INVALID;
	}
	int a = atoi(argv[A_POSITION]);
	int b = atoi(argv[B_POSITION]);
	int p = atoi(argv[P_POSITION]);

	if(a >= 0 && b >= 0 && p > 0) {
		config->a = a;
		config->b = b;
		config->p = p;
		valid = VALID;
	}
	return valid;
}

void print_arguments_message() {
	printf("O programa precisa de pelo menos 3 argumentos: \n");
	printf("1) O valor de a\n");
	printf("2) O valor de b\n");
	printf("3) O valor p que será o módulo da equação\n");
}