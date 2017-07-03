#include "eliptic_curve.h"
#include "mathematical_functions.h"

#include <stdio.h>
#include <stdlib.h>

// y^2 (mod p) = x^3 + ax + b (mod p)
elliptic_curve* find_elliptic_curve_points(int a, int b, int module) {
	int x = 0;
	int y = 0;
	int left_side_result;
	int right_side_result;
	int index = 0;
	elliptic_point** curve_points = NULL;
	elliptic_point* current_point;
	elliptic_curve* elliptic_curve = malloc(sizeof(elliptic_curve));

	for(x = 0; x < module; x++) {
		for(y = 0; y < module; y++) {
			left_side_result = modular_power(y, 2, module);
			right_side_result = get_right_side_result(a, b, module, x);

			if(left_side_result == right_side_result) {
				current_point = malloc(sizeof(elliptic_point));
				current_point->x = x;
				current_point->y = y;
				if(curve_points == NULL) {
					curve_points = malloc(sizeof(elliptic_point*));
				}
				else {
					curve_points = realloc(curve_points, (long unsigned int) (index + 1)
					 * sizeof(elliptic_point*));
				}
				curve_points[index] = current_point;
				index++;
			}
		}
	}

	elliptic_curve->qtd_curve_points = index;
	elliptic_curve->curve_points = curve_points;
	return elliptic_curve;
}

int get_right_side_result(int a, int b, int module, int x) {
	int result = 0;

	result += modular_power(x, 3, module);
	result += (a * x);
	result += b;
	result = result % module;

	return result;
}

elliptic_point* elliptic_point_addition(elliptic_point* p, elliptic_point* q, int a,
 int module) {
 // printf("Somando: \n");
 //	printf("P(%d, %d), Q(%d, %d), Module: %d, a: %d\n", p->x, p->y, q->x, q->y, module, a);
	elliptic_point* r = malloc(sizeof(elliptic_point));
	int lambda = get_lambda(p, q, a, module);
	if(lambda < 0) {
		return NULL;
	}
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
		if(p->y == 0) {
			printf("Não é possível calcular lambda de dois pontos iguais com y = 0\n");
			return -1;
		}
		//printf("Mesmo ponto!\n");
		dividend = (3 * modular_power(p->x, 2, module) + a) % module;
		divisor = (p->y * 2) % module;
	}
	else {
		if(p->x == q->x) {
 			printf("Pontos alinhados verticalmente!\n");
 			printf("Soma igual a O.\n");
 			return -1;
 		}
		//printf("Pontos diferentes!\n");
		divisor = modular_subtraction(q->x, p->x, module);
		dividend = modular_subtraction(q->y, p->y, module);
	}

	modular_divisor = find_inverse_multiplicative(divisor, module);
	if(modular_divisor < 0) {
		printf("Erro ao tentar achar Lambda!\n");
		return -1;
	}
	lambda = (dividend * modular_divisor) % module;

	return lambda;
}

void set_curve_points_order(elliptic_curve* elliptic_curve, int a, int module) {
	int i;
	for(i = 0; i < elliptic_curve->qtd_curve_points; i++) {
		elliptic_curve->curve_points[i]->order = get_point_order(elliptic_curve, 
			elliptic_curve->curve_points[i], a, module);
	}
}

int get_point_order(elliptic_curve* elliptic_curve, elliptic_point* p, int a, int module) {
	int order = 0;
	elliptic_point* result = p;
	elliptic_point* previous_result = NULL;
	int belongs_to_curve = point_on_curve(elliptic_curve, p);
	while(belongs_to_curve == POINT_BELONG_TO_CURVE) {
		if(order > 0) {
			previous_result = result;
		}

		result = elliptic_point_addition(p, result, a, module);
		order++;

		if(previous_result) {
			free(previous_result);
		}

		belongs_to_curve = point_on_curve(elliptic_curve, result);
		if(belongs_to_curve == POINT_DOESNT_BELONG_TO_CURVE) {
			free(result);
			break;
		}

	}

	return order;
}

int point_on_curve(elliptic_curve* elliptic_curve, elliptic_point* p) {
	int i;
	elliptic_point* current_point;

	if(p == NULL) {
		return POINT_DOESNT_BELONG_TO_CURVE;
	}

	for(i = 0; i < elliptic_curve->qtd_curve_points; i++) {
		current_point = elliptic_curve->curve_points[i];
		if(current_point->x == p->x && current_point->y == p->y) {
			return POINT_BELONG_TO_CURVE;
		}
	}
	return POINT_DOESNT_BELONG_TO_CURVE;
	
}

void print_curve(elliptic_curve* elliptic_curve) {
	int i;
	printf("Pontos da curva: \n");
	for(i = 0; i < elliptic_curve->qtd_curve_points; i++) {
		printf("P(%d,%d), Ordem: %d\n", elliptic_curve->curve_points[i]->x,
			elliptic_curve->curve_points[i]->y, elliptic_curve->curve_points[i]->order);
	}
}