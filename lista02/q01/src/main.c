#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_handler.h"
#include "aes.h"
#include "arguments_handler.h"
#include "config.h"

int main(int argc, char* argv[]) {
	int valid_arguments;
	config* config = malloc(sizeof(config));
	valid_arguments = validate_arguments(argc, argv, config);

	return 0;
}