#include <stdio.h>
#include <stdlib.h>
#include "extended_euclidean_algorithm.h"

int main(int argc, char* argv[]) {
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	int gcd = extended_euclidean_algorithm(a, b);

	printf("GCD: %d\n", gcd);
	return 0;
}