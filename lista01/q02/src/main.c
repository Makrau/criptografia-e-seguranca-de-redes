#include <stdio.h>
#include <stdlib.h>

#include "extended_euclidean_algorithm.h"

int main(int argc, char* argv[]) {
	int number;
	int module;

	printf("Digite o valor do número: \n");
	scanf("%d", &number);
	printf("Digite o valor do modulo: \n");
	scanf("%d", &module);

	find_inverse_multiplicative(number,module);

	return 0;
}