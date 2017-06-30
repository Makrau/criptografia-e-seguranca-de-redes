#include "config.h"
#include "mathematical_functions.h"
#include "file_handler.h"

#include <stdio.h>
#include <stdlib.h>

int get_additional_data(config* config) {
	int valid = INVALID;
	valid = get_private_key(config);
	valid = get_algorithm_mode(config);
	valid = get_input_path(config);

	return valid;
}

int get_private_key(config* config) {
	int private_key;
	int phi = phi_n(config->p, config->q);
	private_key = find_inverse_multiplicative(config->public_key, phi);
	if(private_key == 0) {
		printf("Não foi possível gerar a chave privada. Número sem inverso multiplicativo!\n");
		return INVALID;
	}
	else {
		config->private_key = private_key;
		return VALID;
	}
}

int get_algorithm_mode(config* config) {
	int algorithm_mode;
	do {
		print_algorithm_modes();
		scanf("%d", &algorithm_mode);

		if(algorithm_mode == ENCRYPTION_MODE || algorithm_mode == DECRYPTION_MODE) {
			config->algorithm_mode = algorithm_mode;
			return VALID;
		}
		else {
			printf("Modo escolhido inválido! Digite 1 ou 2 para escolher os modos disponíveis.\n");
		}
	} while(1);
}

int get_input_path(config* config) {
	char* input_path;
	printf("Digite o caminho do arquivo de entrada: \n");
	clear_buffer();
	input_path = (char*)read_text_file(stdin);
	config->input_file = fopen(input_path, "rb");
	if(!config->input_file) {
		printf("Não foi possível abrir o arquivo de entrada!\n");
		return INVALID;
	}
	printf("Digite o caminho do arquivo de saída: \n");
	config->output_path = (char*)read_text_file(stdin);
	return VALID;
}



void print_algorithm_modes() {
	printf("Escolha a ação desejada: \n");
	printf("1) Cifração\n");
	printf("2) Decifração\n");
}