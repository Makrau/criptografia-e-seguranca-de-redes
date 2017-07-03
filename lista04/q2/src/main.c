#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "argument_handler.h"
#include "eliptic_curve.h"

int main(int argc, char* argv[]) {
	config* config = malloc(sizeof(config));
	int valid_arguments = verify_arguments(argc, argv, config);
	elliptic_curve* elliptic_curve;
	if(valid_arguments == VALID) {
		elliptic_curve = find_elliptic_curve_points(config->a, config->b, config->module);
		set_curve_points_order(elliptic_curve, config->a, config->module);
		printf("\n");
		print_curve(elliptic_curve);
	}
	else {
		printf("Argumentos inválidos!\n");
	}
	return 0;
}