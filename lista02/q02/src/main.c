#include <stdio.h>
#include <stdlib.h>

#include "des.h"
#include "arguments_handler.h"

int main(int argc, char* argv[]) {
	int valid_arguments;
	des_config* config = malloc(sizeof(des_config));

	valid_arguments = validate_arguments(argc, argv, config);

	if(config->input_file) {
		fclose(config->input_file);
	}
	fclose(config->output_file);

	free(config);
	return 0;
}