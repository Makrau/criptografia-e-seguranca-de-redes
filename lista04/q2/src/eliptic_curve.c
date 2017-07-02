#include "eliptic_curve.h"
#include "mathematical_functions.h"

#include <stdio.h>
#include <stdlib.h>

// y^2 (mod p) = x^3 + ax + b (mod p)
void find_elliptic_curve_points(config* config) {
	int x = 0;
	int y = 0;
	int left_side_result;
	int right_side_result;

	printf("Pontos da curva elíptica E%d(%d, %d)\n", config->module, config->a, config->b);
	for(x = 0; x < config->module; x++) {
		for(y = 0; y < config->module; y++) {
			left_side_result = modular_power(y, 2, config->module);
			right_side_result = get_right_side_result(config, x);

			if(left_side_result == right_side_result) {
				printf("(%d, %d)\n", x, y);
			}
		}
	}
}

int get_right_side_result(config* config, int x) {
	int result = 0;

	result += modular_power(x, 3, config->module);
	result += (config->a * x);
	result += config->b;
	result = result % config->module;

	return result;
}

elliptic_point* elliptic_point_addition(elliptic_point* p, elliptic_point* q, int a,
 int module) {
 	//printf("P(%d, %d), Q(%d, %d), Module: %d, a: %d\n", p->x, p->y, q->x, q->y, module, a);
	elliptic_point* r = malloc(sizeof(elliptic_point));
	int lambda = get_lambda(p, q, a, module);
	//printf("lambda: %d\n", lambda);
	int partial_result;

	// Rx = (lambda ^ 2 - Px - Qx)
	partial_result = modular_power(lambda, 2, module);
	partial_result = modular_subtraction(partial_result, p->x, module);
	partial_result = modular_subtraction(partial_result, q->x, module);
	r->x = partial_result;

	// Ry = (lambda * (Px - Rx) - Py)
	partial_result = modular_subtraction(p->x, r->x, module);
	partial_result = (lambda * partial_result) % module;
	partial_result = modular_subtraction(partial_result, p->y, module);
	r->y = partial_result;

	return r;
}

int same_point(elliptic_point* p, elliptic_point* q) {

	if(p->x == q->x && p->y == q->y) {
		return SAME_POINT;
	}
	else {
		return DIFFERENT_POINTS;
	}
}

int get_lambda(elliptic_point* p, elliptic_point* q, int a, int module) {
	int lambda;
	int divisor;
	int dividend;
	int modular_divisor;
	int is_same_point = same_point(p, q);
	if(is_same_point) {
		//printf("Mesmo ponto!\n");
		dividend = (3 * modular_power(p->x, 2, module) + a) % module;
		divisor = (p->y * 2) % module;
	}
	else {
		//printf("Pontos diferentes!\n");
		divisor = modular_subtraction(q->x, p->x, module);
		dividend = modular_subtraction(q->y, p->y, module);
	}

	modular_divisor = find_inverse_multiplicative(divisor, module);
	lambda = (dividend * modular_divisor) % module;

	return lambda;
}