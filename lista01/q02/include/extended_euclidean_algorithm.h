#ifndef EXTENDED_EUCLIDEAN_ALGORITHM_H
#define EXTENDED_EUCLIDEAN_ALGORITHM_H

typedef struct _division_struct{
	int number;
	int divisor;
	int quotient;
	int remainder;
	struct _division_struct* next;
	struct _division_struct* previous;
} division_struct;

int extended_euclidean_algorithm(int a, int b, division_struct* node);
int find_inverse_multiplicative(int number, int module);
void print_list(division_struct* header);
division_struct* get_tail(division_struct* header);

#endif