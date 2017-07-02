#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "argument_handler.h"
#include "eliptic_curve.h"

int main(int argc, char* argv[]) {
	config* config = malloc(sizeof(config));
	int valid_arguments = verify_arguments(argc, argv, config);
	elliptic_point* p = malloc(sizeof(elliptic_point));
	elliptic_point* q = malloc(sizeof(elliptic_point));
	elliptic_point* r;
	if(valid_arguments == VALID) {
		find_elliptic_curve_points(config);
		printf("Digite as coordenadas de p: \n");
		scanf("%d %d", &p->x, &p->y);
		printf("Digite as coordenadas de q: \n");
		scanf("%d %d", &q->x, &q->y);
		r = elliptic_point_addition(p, q, config->a, config->module);
		printf("R = (%d, %d)\n", r->x, r->y);
	}
	else {
		printf("Argumentos inválidos!\n");
	}
	return 0;
}