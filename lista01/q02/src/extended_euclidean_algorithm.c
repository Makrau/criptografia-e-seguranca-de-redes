#include <stdio.h>
#include <stdlib.h>

#include "extended_euclidean_algorithm.h"

int find_inverse_multiplicative(int number, int module) {
	int gcd = extended_euclidean_algorithm(number, module);
	if(gcd != 1) {
		printf("numero NÃO possui inverso multiplicativo!\n");
		//return 0;
	}
	else {
		printf("numero POSSUI inverso multiplicativo\n");
	}

	printf("GCD: %d\n", gcd);

	return 0;
}

int extended_euclidean_algorithm(int a, int b) {
	int remainder;
	if(b == 0) {
		return a;
	}
	else {
		remainder = a % b;

		return extended_euclidean_algorithm(b, remainder);
	}
}