#include "extended_euclidean_algorithm.h"

int phi_n(int p, int q) {
	int phi_n;
	phi_n = (p-1) * (q-1);

	return phi_n;
}