#include <stdio.h>
#include <stdlib.h>

#include "extended_euclidean_algorithm.h"

int find_inverse_multiplicative(int number, int module) {
	division_struct* header = malloc(sizeof(division_struct));
	division_struct* tail = get_tail(header);
	header->previous = NULL;

	if(number > module) {
		number = number % module;
		printf("numero dentro do modulo: %d\n", number);
	}

	int gcd = extended_euclidean_algorithm(module, number, header);

	if(gcd != 1) {
		printf("numero NÃO possui inverso multiplicativo!\n");
		return 0;
	}
	else {
		printf("numero POSSUI inverso multiplicativo\n");
	}

	//calculate_inverse(tail, module);
	print_list(header);

	return 0;
}

int extended_euclidean_algorithm(int a, int b, division_struct* node) {
	int remainder;
	int quotient;
	division_struct* next;
	if(b == 0) {
		return a;
	}
	else if(b == 1) {
		return 1;
	}
	else {
		quotient = a / b;
		remainder = a % b;
		

		node->number = a;
		node->divisor = b;
		node->remainder = remainder;
		node->quotient = quotient;

		if(remainder == 0 || remainder == 1) {
			node->next = NULL;
		}
		else {
			next = malloc(sizeof(division_struct));
			next->previous = node;

			node->next = next;
		}

		return extended_euclidean_algorithm(b, remainder, next);
	}
}

void print_list(division_struct* header) {
	division_struct* current_node = header;
	while(current_node != NULL){
		printf("Number: %d\n", current_node->number);
		printf("Divisor: %d\n", current_node->divisor);
		printf("Quotient: %d\n", current_node->quotient);
		printf("Remainder: %d\n", current_node->remainder);
		printf("\n");

		current_node = current_node->next;
	}
}

division_struct* get_tail(division_struct* header) {
	division_struct* current_node = header;
	while(current_node->next != NULL) {
		current_node = current_node->next;
	}

	return current_node;
}

/*int calculate_inverse(division_struct* node, int module, int number) {
	int current_number = node->number;
	int current_quotient = - (node->quotient);
	int current_divisor = node->divisor;

	if(node->number == module) {
		if(current_divisor == number){
			return current_quotient;
		}
		else {
			printf("problema ao calcular inverso....\n");
		}
	}
	else {
		if(node->number == number) {
			return 
		}
	}
}*/