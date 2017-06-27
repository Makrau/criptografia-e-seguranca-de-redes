#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "mathematical_functions.h"

int find_inverse_multiplicative(int number, int module) {
	int gcd;
	int inverse_multiplicative;
	extended_struct* first = malloc(sizeof(extended_struct));
	extended_struct* second = malloc(sizeof(extended_struct));
	extended_struct* tail;

	first->x = 1;
	first->y = 0;
	first->next = second;
	first->previous = NULL;

	second->x = 0;
	second->y = 1;
	second->previous = first;

	gcd = extended_euclidean_algorithm(module, number, second);

	if(gcd != 1) {
		printf("numero NÃO possui inverso multiplicativo!\n");

		return 0;
	}
	else {
		printf("numero POSSUI inverso multiplicativo\n");
			tail = get_tail(first);
		inverse_multiplicative = get_inverse(tail->y, module);

		printf("Inverso multiplicativo de %d no módulo %d: %d\n",
			number, module, inverse_multiplicative);
		return inverse_multiplicative;
	}
}

int extended_euclidean_algorithm(int a, int b, extended_struct* previous) {
	int remainder;
	int quotient;
	extended_struct* current = malloc(sizeof(extended_struct));


	if(b == 0) {
		return a;
	}
	else if(b == 1) {
		return 1;
	}
	else {
		remainder = a % b;
		quotient = a / b;

		current->quotient = quotient;
		current->x = previous->previous->x - (quotient * previous->x);
		current->y = previous->previous->y - (quotient * previous->y);

		previous->next = current;
		current->previous = previous;
		current->next = NULL;
		return extended_euclidean_algorithm(b, remainder, current);
	}
}

int phi_n(int p, int q) {
	int phi_n;
	phi_n = (p-1) * (q-1);

	return phi_n;
}

extended_struct* get_tail(extended_struct* header) {
	extended_struct* current = header;

	while(current->next != NULL) {
		current = current->next;
	}

	return current;
}

int get_inverse(int inverse, int module) {
	if(inverse < 0) {
		inverse = (inverse + module) % module;
	}

	if(inverse > module) {
		inverse = inverse % module;
	}

	return inverse;
}

int modular_power(int number, int power, int module) {
	printf("number: %d\n", number);
	printf("power: %d\n", power);
	printf("module: %d\n", module);
	int result = 1;
	int counter = 0;

	for(counter = 0; counter <= power; counter++) {
		result = (result * number) % module;
	}

	result = result % module;

	return result;
}