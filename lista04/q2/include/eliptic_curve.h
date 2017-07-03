#ifndef ELIPTIC_CURVE_H
#define ELIPTIC_CURVE_H

#include "config.h"

#define DIFFERENT_POINTS 0
#define SAME_POINT 1
#define POINT_DOESNT_BELONNG_TO_CURVE 0
#define POINT_BELONG_TO_CURVE 1

typedef struct elliptic_point {
	int x;
	int y;
	int order;
}elliptic_point;

typedef struct elliptic_curve {
	elliptic_point** elliptic_curve_points;
	int qtd_curve_points;
}elliptic_curve;

elliptic_curve* find_elliptic_curve_points(config* config);
int get_right_side_result(config* config, int x);
elliptic_point* elliptic_point_addition(elliptic_point* p, elliptic_point* q, int a,
 int module);
int same_point(elliptic_point* p, elliptic_point* q);
int get_lambda(elliptic_point* p, elliptic_point* q, int a, int module);
void set_curve_points_order(elliptic_point** curve_points, config* config);
void print_curve(elliptic_curve* elliptic_curve);

#endif