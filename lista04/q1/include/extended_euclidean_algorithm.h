#ifndef EXTENDED_EUCLIDEAN_ALGORITHM_H
#define EXTENDED_EUCLIDEAN_ALGORITHM_H

typedef struct _extended_struct {
	int quotient;
	int x;
	int y;
	struct _extended_struct* next;
	struct _extended_struct* previous;
} extended_struct;

int extended_euclidean_algorithm(int a, int b);
int recursive_step(int a, int b, extended_struct* previous);

#endif