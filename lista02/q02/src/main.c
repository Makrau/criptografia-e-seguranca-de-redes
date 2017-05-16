#include <stdio.h>
#include <stdlib.h>

#include "des.h"
#include "arguments_handler.h"

int main(int argc, char* argv[]) {
	int valid_arguments;
	des_config* config = malloc(sizeof(des_config));

	valid_arguments = validate_arguments(argc, argv, config);
	return 0;
}