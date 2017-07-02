#include "eliptic_curve.h"
#include "mathematical_functions.h"

#include <stdio.h>


// y^2 (mod p) = x^3 + ax + b (mod p)
void find_elliptic_curve_points(config* config) {
	int x = 0;
	int y = 0;
	int left_side_result;
	int right_side_result;

	printf("Pontos da curva elíptica E%d(%d, %d)\n", config->p, config->a, config->b);
	for(x = 0; x < config->p; x++) {
		for(y = 0; y < config->p; y++) {
			left_side_result = modular_power(y, 2, config->p);
			right_side_result = get_right_side_result(config, x);

			if(left_side_result == right_side_result) {
				printf("(%d, %d)\n", x, y);
			}
		}
	}
}

int get_right_side_result(config* config, int x) {
	int result = 0;

	result += modular_power(x, 3, config->p);
	result += (config->a * x);
	result += config->b;
	result = result % config->p;

	return result;
}