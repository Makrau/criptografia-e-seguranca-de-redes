#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "argument_handler.h"
#include "eliptic_curve.h"

int main(int argc, char* argv[]) {
	config* config = malloc(sizeof(config));
	int valid_arguments = verify_arguments(argc, argv, config);

	if(valid_arguments == VALID) {
		find_elliptic_curve_points(config);
	}
	else {
		printf("Argumentos inválidos!\n");
	}
	return 0;
}