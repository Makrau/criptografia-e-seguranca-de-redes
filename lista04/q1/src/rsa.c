#include "mathematical_functions.h"
#include "config.h"

void get_private_key(config* config) {
	int private_key;
	int phi = phi_n(config->p, config->q);
	private_key = find_inverse_multiplicative(config->public_key, phi);
	config->private_key = private_key;
	printf("private key: %d\n", private_key);
}