#include <stdio.h>
#include <stdlib.h>

#include "argument_handler.h"
#include "rsa.h"
#include "mathematical_functions.h"

int verify_arguments(int argc, char* argv[], config* config) {
	if(argc != 4) {
		arguments_description();
		return INVALID;
	}

	config->p = atoi(argv[PRIME_P]);
	config->q = atoi(argv[PRIME_Q]);
	int public_key_e = atoi(argv[PUBLIC_KEY_E]);

	int valid = verify_public_key(public_key_e, config);

	return valid;
}

int verify_public_key(int public_key_e, config* config) {
	int phi = phi_n(config->p, config->q);
	int public_key = public_key_e;
	int gcd;
	extended_struct* first = malloc(sizeof(extended_struct));
	extended_struct* second = malloc(sizeof(extended_struct));

	first->x = 1;
	first->y = 0;
	first->next = second;
	first->previous = NULL;

	second->x = 0;
	second->y = 1;
	second->previous = first;

	do {
		gcd = extended_euclidean_algorithm(phi, public_key, second);
		if(gcd == 1) {
			config->public_key = public_key;
			return VALID;
		}
		else {
			printf("GCD: %d\n", gcd);
			printf("public key: %d\n", public_key);
			printf("phi: %d\n", phi);
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