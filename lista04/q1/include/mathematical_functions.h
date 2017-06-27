#ifndef MATHEMATICAL_FUNCTIONS_H
#define MATHEMATICAL_FUNCTIONS_H

typedef struct _extended_struct {
	int quotient;
	int x;
	int y;
	struct _extended_struct* next;
	struct _extended_struct* previous;
} extended_struct;

int find_inverse_multiplicative(int number, int module);
int extended_euclidean_algorithm(int a, int b, extended_struct* previous);
int recursive_step(int a, int b, extended_struct* previous);
int phi_n(int p, int q);
extended_struct* get_tail(extended_struct* header);
int get_inverse(int inverse, int module);
int modular_power(int number, int power, int module);

#endif