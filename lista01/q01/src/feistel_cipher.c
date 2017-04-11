#include "feistel_cipher.h"

#include <stdint.h>

void encrypt(FILE* input_file, FILE* output_file, int number_of_rounds,
	uint64_t key) {
	uint32_t initial_left;
	uint32_t initial_right;
	size_t aux;

	uint64_t current_block;

	while(feof(input_file) == 0) {
		memset(&current_block, 0, sizeof(current_block));
		aux = fread(&current_block, 1, sizeof(current_block), input_file);

		if(!aux) {
			break;
		}

		initial_left = (current_block >> 32) & 0xFFFFFFFF;
		initial_right =  current_block & 0xFFFFFFFF;

		current_block = rounds_encrypt(initial_left, initial_right, number_of_rounds, key);

		fwrite(&current_block, 1, sizeof(current_block), output_file);
	}
}

uint64_t rounds_encrypt(uint32_t left, uint32_t right, int number_of_rounds,
	uint64_t keys) {
	uint32_t next_left;
	uint32_t next_right;
	uint64_t final_block;
	uint64_t sub_keys[number_of_rounds];
	int current_round;

	sub_keys = generate_sub_keys(key, number_of_rounds);

	for(current_round = 0; current_round < number_of_rounds; current_round++) {
		next_left = right;
		next_right = round_function(right, sub_keys[current_round]) ^ left;

		if(current_round == (number_of_rounds - 1)) {
			left = next_right;
			right = next_left;
		}
		else {
			left = next_left;
			right = next_right;
		}
	}

	final_block = (left << 32) | right;

	return final_block;
}

uint32_t round_function(uint32_t half_block, uint64_t current_key) {

}

uint64_t generate_sub_keys(uint64_t key, number_of_rounds) {
	uint64_t permuted_choice1;
	uint64_t sub_keys[number_of_rounds];
	uint32_t left_key_half;
	uint32_t right_key_half;
	uint64_t sub_key;

	permuted_choice1 = key >> 8;
	left_key_half = (permuted_choice1 >> 24) & 0xFFFFFFFF;
	right_key_half = permuted_choice1 & 0xFFFFFFFF;

	for(int i; i < number_of_rounds; i++) {
		
		sub_key = 
	}
}