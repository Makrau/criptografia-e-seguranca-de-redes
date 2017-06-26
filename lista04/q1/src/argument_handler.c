#include <stdio.h>
#include <stdlib.h>

#include "argument_handler.h"
#include "rsa.h"
#include "extended_euclidean_algorithm.h"

int verify_arguments(int argc, char* argv[], config* config) {
	if(argc != 4) {
		arguments_description();
		return INVALID;
	}

	int p = atoi(argv[PRIME_P]);
	int q = atoi(argv[PRIME_Q]);
	int public_key_e = atoi(argv[PUBLIC_KEY_E]);

	int valid = verify_public_key(p, q, public_key_e, config);

	return valid;
}

int verify_public_key(int p, int q, int public_key_e, config* config) {
	int n = p * q;
	int phi = phi_n(p, q);
	int public_key = public_key_e;
	int gcd;
	config->n = n;

	do {
		gcd = extended_euclidean_algorithm(phi, public_key);
		if(gcd == 1) {
			config->public_key = public_key;
			return VALID;
		}
		else {
			printf("Chave publica inválida!\n");
			printf("digite uma nova chave pública: \n");
			scanf("%d", &public_key);
		}
	} while(gcd != 1);

	// Not suposed to reach here...
	return INVALID;
}

void arguments_description() {
	printf("This program takes 3 arguments:: two primes p and q and the public key e.\n");
	printf("The program will verify if the public key e its a valid key.\n");
	printf("The program don't verify if the values of p and q are really primes.\n");
	printf("Inform invalid p and q might lead to unapropriate program behavior.\n");
}