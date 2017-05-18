#include <stdio.h>
#include <stdlib.h>

#include "des.h"
#include "arguments_handler.h"
#include "binary_handler.h"
#include "cbc.h"
#include "config.h"

int main(int argc, char* argv[]) {
	int valid_arguments;
	config* config = malloc(sizeof(config));

	valid_arguments = validate_arguments(argc, argv, config);

	if(valid_arguments == VALID_ARGUMENTS) {
		run_cbc(config);
	}

	free(config);
	return 0;
}
