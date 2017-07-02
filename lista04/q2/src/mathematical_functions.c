#include "mathematical_functions.h"

int modular_power(int number, int power, int module) {
	int result = 1;
	int counter = 0;

	for(counter = 0; counter < power; counter++) {
		result = (result * number) % module;
	}

	return result;
}