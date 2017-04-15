#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "des.h"
#include "binary_handler.h"

int ip[] = {58, 50, 42, 34, 26, 18, 10, 2,
						60, 52, 44, 36, 28, 20, 12, 4,
						62, 54, 46, 38, 30, 22, 14, 6,
						64, 56, 48, 40, 32, 24, 16, 8,
						57, 49, 41, 33, 25, 17,  9, 1,
						59, 51, 43, 35, 27, 19, 11, 3,
						61, 53, 45, 37, 29, 21, 13, 5,
						63, 55, 47, 39, 31, 23, 15, 7};

int ip_inverse[] =   {40,  8, 48, 16, 56, 24, 64, 32,
											39,  7, 47, 15, 55, 23, 63, 31,
											38,  6, 46, 14, 54, 22, 62, 30,
											37,  5, 45, 13, 53, 21, 61, 29,
											36,  4, 44, 12, 52, 20, 60, 28,
											35,  3, 43, 11, 51, 19, 59, 27,
											34,  2, 42, 10, 50, 18, 58, 26,
											33,  1, 41,  9, 49, 17, 57, 25};

int message_expansion[] =  {32,  1,  2,  3,  4,  5,
														 4,  5,  6,  7,  8,  9,
														 8,  9, 10, 11, 12, 13,
														12, 13, 14, 15, 16, 17,
														16, 17, 18, 19, 20, 21,
														20, 21, 22, 23, 24, 25,
														24, 25, 26, 27, 28, 29,
														28, 29, 30, 31, 32,  1};

int S1[] = {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
						 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
						 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
						15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13};

int S2[] = {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
						 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
						 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
						13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9};

int S3[] = {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
						13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
						13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
						 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12};

int S4[] = { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
						13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
						10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
						 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14};

int S5[] = { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
						14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
						 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
						11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3};

int S6[] = {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
						10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
						 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
						 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13};

int S7[] = { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
						13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
						 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
						 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12};

int S8[] = {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
						 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
						 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
						 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11};

int p_table[] = { 16,  7, 20, 21,
									29, 12, 28, 17,
									 1, 15, 23, 26,
									 5, 18, 31, 10,
									 2,  8, 24, 14,
									32, 27,  3,  9,
									19, 13, 30,  6,
									22, 11,  4, 25};

int pc1[] =  {57, 49,  41, 33,  25,  17,  9,
							 1, 58,  50, 42,  34,  26, 18,
							10,  2,  59, 51,  43,  35, 27,
							19, 11,   3, 60,  52,  44, 36,
							63, 55,  47, 39,  31,  23, 15,
							 7, 62,  54, 46,  38,  30, 22,
							14,  6,  61, 53,  45,  37, 29,
							21, 13,   5, 28,  20,  12,  4};
							
int key_shift_sizes[] = {1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int pc2[] =  {14, 17, 11, 24,  1,  5,
							 3, 28, 15,  6, 21, 10,
							23, 19, 12,  4, 26,  8,
							16,  7, 27, 20, 13,  2,
							41, 52, 31, 37, 47, 55,
							30, 40, 51, 45, 33, 48,
							44, 49, 39, 56, 34, 53,
							46, 42, 50, 36, 29, 32};

unsigned char* generate_key() {
	int i;
	unsigned char* key = (unsigned char*) malloc( KEY_CHAR_SIZE * sizeof(char));
	FILE* key_file = fopen("keyfile", "wb");

	unsigned int seed = (unsigned int)time(NULL);
	srand (seed);

	if (!key_file) {
		printf("Problems opening the keyfile");
		return NULL;
	}

	for (i=0; i<8; i++) {
		key[i] = rand()%255;
	}


	fwrite(key, 1, KEY_CHAR_SIZE, key_file);
	fclose(key_file);

	return key;
}

unsigned char* generate_binary_key_string(unsigned char* key) {
	unsigned char* binary_key_string = (unsigned char*)
		malloc(KEY_CHAR_SIZE * BYTE_SIZE * sizeof(char));
	unsigned char* binary_char_string;

	for(int i = 0; i < KEY_CHAR_SIZE; i++) {
		binary_char_string = translate_char_to_binary_string(key[i]);
		if(i == 0) {
			strncpy((char*) binary_key_string, (char*) binary_char_string, BYTE_SIZE);
		}
		else{
			strncat((char*) binary_key_string, (char*) binary_char_string, BYTE_SIZE);
		}
	}

	return binary_key_string;
}

unsigned char* generate_binary_message_string(unsigned char* message) {
	unsigned char* binary_message_string = (unsigned char*)
		malloc(KEY_CHAR_SIZE * BYTE_SIZE * sizeof(char));
		unsigned char* binary_char_string;

		for(int i = 0; i < 8; i++) {
		binary_char_string = translate_char_to_binary_string(message[i]);
		if(i == 0) {
			strncpy((char*) binary_message_string, (char*) binary_char_string, BYTE_SIZE);
		}
		else{
			strncat((char*) binary_message_string, (char*) binary_char_string, BYTE_SIZE);
		}
	}

	return binary_message_string;
}

unsigned char* pc1_function(unsigned char* key_string) {
	unsigned char* permuted_key = (unsigned char*)
		malloc(PC1_SIZE * sizeof(char) + 1);
		int bit_position;

	for(int i = 0; i < PC1_SIZE; i++) {
		bit_position = pc1[i];
		permuted_key[i] = key_string[bit_position - 1];
	}

	permuted_key[56] = '\0';

	return permuted_key;
}

key_structure* generate_sub_keys(unsigned char* key_string) {
	unsigned char* permuted_key = pc1_function(key_string);
	key_structure* sub_keys = malloc(KEY_C_D_AMOUNT * sizeof(key_structure));

	// Split permuted key into C0 and D0
	strncpy((char*) sub_keys[0].c, (char*) permuted_key, 28);
	strncpy((char*) sub_keys[0].d, (char*) permuted_key + C_D_SIZE, C_D_SIZE);

	sub_keys[0].c[28] = '\0';
	sub_keys[0].d[28] = '\0';

	for(int round = 1; round < KEY_C_D_AMOUNT; round++) {
		make_key_rounds(sub_keys, round);
	}

	return sub_keys;
}

void make_key_rounds(key_structure* sub_keys, int round) {
	unsigned char temporary_string[56];
	int left_shift = key_shift_sizes[round];

	// making left shifts
	for(int i = 0; i < C_D_SIZE; i++) {
		
		sub_keys[round].c[i] = sub_keys[round -1].c[(i+left_shift) % C_D_SIZE];
		sub_keys[round].d[i] = sub_keys[round - 1].d[(i+left_shift) % C_D_SIZE];
	}

	sub_keys[round].c[28] = '\0';
	sub_keys[round].d[28] = '\0';

	strcpy((char*)temporary_string, (char*)sub_keys[round].c);
	strcat((char*)temporary_string, (char*)sub_keys[round].d);

	// making permutation 2
	for(int i = 0; i < KEY_BIT_SIZE; i++) {
		sub_keys[round].key[i] = temporary_string[pc2[i] - 1];
	}

	sub_keys[round].key[48] = '\0';
}

unsigned char* ip_function(unsigned char* message) {
	unsigned char* permuted_message = malloc(64 * sizeof(char));

	for(int i = 0; i < 64; i++) {
		permuted_message[i] = message[ip[i] - 1];
	}

	return permuted_message;
}

unsigned char* encrypt_message(unsigned char* message, key_structure* sub_keys) {
	unsigned char* initial_permutation;
	unsigned char pre_output[64];
	unsigned char* encrypted_message_bit_string;
	unsigned char* encrypted_message = malloc(8 *sizeof(char));
	unsigned char piece_string[9];
	block_structure blocks[17];
	initial_permutation = ip_function(message);
	printf("I: %s\n", initial_permutation);

	strncpy((char*) blocks[0].left_block, (char*)initial_permutation, HALF_BLOCK_SIZE);
	strncpy((char*)blocks[0].right_block, (char*)initial_permutation + HALF_BLOCK_SIZE, HALF_BLOCK_SIZE);

	blocks[0].left_block[32] = '\0';
	blocks[0].right_block[32] = '\0';

	for(int i = 1; i < 17; i++) {
		printf("Round %d\n", i);
		make_half_block_rounds(blocks, sub_keys, i);
		printf("\n");
	}

	strcpy((char*)pre_output,(char*) blocks[16].right_block);
	strcat((char*)pre_output,(char*) blocks[16].left_block);

	encrypted_message_bit_string = final_permutation(pre_output);

	for(int i = 0; i < BYTE_SIZE; i ++) {
		strncpy((char*)piece_string, (char*)encrypted_message_bit_string + (i * BYTE_SIZE), 
			BYTE_SIZE);
		piece_string[8] = '\0';
		printf("piece string: %s\n", piece_string);
		printf("piece char: %d\n", translate_binary_string_to_int((char*)piece_string));
		encrypted_message[i] = translate_binary_string_to_int((char*)piece_string);
	}

	free(initial_permutation);
	
	return encrypted_message;
}

void make_half_block_rounds(block_structure* blocks, key_structure* sub_keys, int round) {
	unsigned char* f_string;
	unsigned char* round_right_block;

	strcpy((char*)blocks[round].left_block, (char*)blocks[round - 1].right_block);

	f_string = f_function(blocks[round - 1].right_block, sub_keys[round].key);

	round_right_block = string_xor(f_string, blocks[round -1].left_block);

	strcpy((char*)blocks[round].right_block, (char*) round_right_block);

	free(f_string);
	free(round_right_block);
}
	
	 

unsigned char* f_function(unsigned char* right_block, unsigned char* key) {
	unsigned char* expanded_block;
	unsigned char* xor_string;
	unsigned char* f_string;
	unsigned char* s_string;

	expanded_block = expansion_function(right_block);
	xor_string = string_xor(expanded_block, key);
	s_string = s_box_function(xor_string);
	f_string = p_function(s_string);

	printf("R: %s\n", right_block);
	printf("E: %s\n", expanded_block);
	printf("K: %s\n", key);
	printf("X: %s\n", xor_string);
	printf("S: %s\n", s_string);
	printf("F: %s\n", f_string);
	printf("\n");

	free(expanded_block);
	free(xor_string);
	free(s_string);

	return f_string;
}

unsigned char* s_box_function(unsigned char* input) {
	unsigned char* s_string = malloc(32 * sizeof(char));
	int i;
	int j;
	int s_value;
	int bit_group_start;
	char i_string[2];
	char j_string[4];
	unsigned char* temporary_string;

	for(int counter = 0; counter < S_AMOUNT; counter++) {
		bit_group_start = counter * S_BIT_GROUP;
		i_string[0] = input[bit_group_start];
		i_string[1] = input[bit_group_start + 5];
		strncpy(j_string,(char*) input + (bit_group_start + 1), 4);

		i = translate_binary_string_to_int(i_string);
		j = translate_binary_string_to_int(j_string);

		s_value = find_s_value(counter + 1, i, j);
		temporary_string = translate_char_to_binary_string(s_value);

		if(counter == 0) {
			strncpy((char*)s_string, (char*)temporary_string + S_OUTPUT_SIZE, S_OUTPUT_SIZE);
		}
		else{
			strncat((char*)s_string, (char*)temporary_string + S_OUTPUT_SIZE, S_OUTPUT_SIZE);
		}
	}

	return s_string;
}

unsigned char* final_permutation(unsigned char* pre_output) {
	unsigned char* final_string = malloc(64 * sizeof(char));

	for(int i = 0; i < 64; i++) {
		final_string[i] = pre_output[ip_inverse[i] - 1];
	}

	return final_string;
}

unsigned char* p_function(unsigned char* s_string) {
	unsigned char* p_string = malloc(HALF_BLOCK_SIZE * sizeof(char));

	for(int i = 0; i < HALF_BLOCK_SIZE; i++) {
		p_string[i] = s_string[p_table[i] - 1];
	}

	return p_string;
}
int find_s_value(int counter, int i, int j) {
	int index = ((i * 16) + j);

	switch(counter) {
		case 1:
			return S1[index];

		case 2:
			return S2[index];

		case 3:
			return S3[index];

		case 4:
			return S4[index];

		case 5:
			return S5[index];

		case 6:
			return S6[index];

		case 7:
			return S7[index];

		case 8:
			return S8[index];

		default:
			printf("error on find_s_value!\n");
			return -1;
	}
}

unsigned char* expansion_function(unsigned char* right_block) {
	unsigned char* expanded_block = malloc(EXPANDED_BLOCK_SIZE * sizeof(char));

	for(int i = 0; i < EXPANDED_BLOCK_SIZE; i++) {
		expanded_block[i] = right_block[message_expansion[i] - 1];
	}

	return expanded_block;
}

unsigned char* decrypt_message(unsigned char* message, key_structure* sub_keys) {

}