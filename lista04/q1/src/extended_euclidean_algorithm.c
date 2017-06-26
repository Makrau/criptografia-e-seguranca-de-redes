#include <stdlib.h>

#include "extended_euclidean_algorithm.h"

int extended_euclidean_algorithm(int a, int b) {
	extended_struct* first = malloc(sizeof(extended_struct));
	extended_struct* second = malloc(sizeof(extended_struct));

	first->x = 1;
	first->y = 0;
	first->next = second;
	first->previous = NULL;

	second->x = 0;
	second->y = 1;
	second->previous = first;

	return recursive_step(a, b, second);
}

int recursive_step(int a, int b, extended_struct* previous) {
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
		return recursive_step(b, remainder, current);
	}
}