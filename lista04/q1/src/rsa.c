#include "rsa.h"
#include "mathematical_functions.h"
#include "config.h"

#include <stdio.h>
#include <stdlib.h>

void get_additional_data(config* config) {
	get_private_key(config);
	get_algorithm_mode(config);
	get_input_path(config);
}

void get_private_key(config* config) {
	int private_key;
	int phi = phi_n(config->p, config->q);
	private_key = find_inverse_multiplicative(config->public_key, phi);
	config->private_key = private_key;
	printf("private key: %d\n", private_key);
}

void get_algorithm_mode(config* config) {
	int algorithm_mode;
	do {
		print_algorithm_modes();
		scanf("%d", &algorithm_mode);

		if(algorithm_mode == ENCRYPTION_MODE || algorithm_mode == DECRYPTION_MODE) {
			config->algorithm_mode = algorithm_mode;
			break;
		}
		else {
			printf("Modo escolhido inválido! Digite 1 ou 2 para escolher os modos disponíveis.\n");
		}
	} while(1);
}


void get_input_path(config* config) {

}

void print_algorithm_modes() {
	printf("Escolha a ação desejada: \n");
	printf("1) Cifração\n");
	printf("2) Decifração\n");
}