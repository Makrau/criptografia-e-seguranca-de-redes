#ifndef ELIPTIC_CURVE_H
#define ELIPTIC_CURVE_H

#include "config.h"

typedef struct elliptic_point {
	int x;
	int y;
}elliptic_point;

void find_elliptic_curve_points(config* config);
int get_right_side_result(config* config, int x);
elliptic_point* elliptic_point_addition(elliptic_point* p, elliptic_point* q, int module);

#endif