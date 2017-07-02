#ifndef ELIPTIC_CURVE_H
#define ELIPTIC_CURVE_H

#include "config.h"

#define DIFFERENT_POINTS 0
#define SAME_POINT 1

typedef struct elliptic_point {
	int x;
	int y;
}elliptic_point;

void find_elliptic_curve_points(config* config);
int get_right_side_result(config* config, int x);
elliptic_point* elliptic_point_addition(elliptic_point* p, elliptic_point* q, int a,
 int module);
int same_point(elliptic_point* p, elliptic_point* q);
int get_lambda(elliptic_point* p, elliptic_point* q, int a, int module);

#endif