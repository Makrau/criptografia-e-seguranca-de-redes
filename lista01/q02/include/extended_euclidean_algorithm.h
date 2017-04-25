#ifndef EXTENDED_EUCLIDEAN_ALGORITHM_H
#define EXTENDED_EUCLIDEAN_ALGORITHM_H

typedef struct _extended_struct {
	int quotient;
	int x;
	int y;
	struct _extended_struct* next;
	struct _extended_struct* previous;
} extended_struct;

int extended_euclidean_algorithm(int a, int b, extended_struct* previous);
int find_inverse_multiplicative(int number, int module);
void print_list(extended_struct* header);
extended_struct* get_tail(extended_struct* header);
int get_inverse(int inverse, int module);

#endif