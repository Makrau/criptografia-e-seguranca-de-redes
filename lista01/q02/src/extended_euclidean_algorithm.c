#include <stdio.h>
#include <stdlib.h>

#include "extended_euclidean_algorithm.h"

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


	if(number > module) {
		number = number % module;
		printf("numero dentro do modulo: %d\n", number);
	}

	gcd = extended_euclidean_algorithm(module, number, second);

	if(gcd != 1) {
		printf("numero NÃO possui inverso multiplicativo!\n");
		return 0;
	}
	else {
		printf("numero POSSUI inverso multiplicativo\n");
			tail = get_tail(first);
		inverse_multiplicative = get_inverse(tail->y, module);

		//print_list(first);
		printf("Inverso multiplicativo de %d no módulo %d: %d\n",
			number, module, inverse_multiplicative);
	}

	return 0;
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

void print_list(extended_struct* header) {
	extended_struct* current = header;

	while(current != NULL) {
		printf("M: %d\t", current->x);
		printf("N: %d\n", current->y);
		current = current->next;
	}
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