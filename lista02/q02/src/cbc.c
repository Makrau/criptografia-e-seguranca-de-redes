#include <stdlib.h>
#include <string.h>

#include "cbc.h"
#include "binary_handler.h"
#include "key_handler.h"
#include "des.h"

unsigned char initialization_vector[8] = {(char)233, (char)122, (char)212, (char)167,
 (char)122, (char)187, (char)200};

unsigned char* cbc_pre_process(unsigned char* message, unsigned char* previous_ciphertext) {
	unsigned char* pre_message_processed = malloc(CHAR_BIT_SIZE * sizeof(char) + 1);
	int i = 0;
	unsigned char xor_char;
	for(i = 0; i < 8; i++) {
		xor_char = message[i] ^ previous_ciphertext[i];
		pre_message_processed[i] = xor_char;
	}

	pre_message_processed[9] = '\0';

	return pre_message_processed;
}

void run_cbc(config* config) {
	unsigned char* message = malloc(8 * sizeof(char));
	unsigned char* key;
	unsigned char* algorithm_result;
	unsigned char* previous_ciphertext = malloc(9 * sizeof(char));
	unsigned char* cbc_pre_processed_message;
	int flag = 1;

	//Searching for keyfile. If not found, generate a new key.
	key = read_key();
	strncpy((char*)previous_ciphertext, (char*)initialization_vector, 8);
	previous_ciphertext[8] = '\0';

	if(config->input_file) {
		while(flag){
			size_t bytes_read = fread(message, sizeof(char), 8, config->input_file);
			
			if(feof(config->input_file)){
				//printf("Hit final of the file!\n");
				//printf("Bytes read: %d\n", (int)bytes_read);
				if(bytes_read == 0) {
					return;
				}
				if(bytes_read != 8) {
					//process_final_message(message);
					return;
				}
				fclose(config->input_file);
				fclose(config->output_file);
				flag = 0;
			}

			//printf("M: %s\n", message);
			if(config->algorithm_mode == ENCRYPTION_MODE){
				cbc_pre_processed_message = cbc_pre_process(message, previous_ciphertext);
				algorithm_result = des_algorithm(cbc_pre_processed_message, config->algorithm_mode,
					key);
				fwrite(algorithm_result, sizeof(char), 8, config->output_file);
				strncpy((char*)previous_ciphertext, (char*)algorithm_result, 8);
				previous_ciphertext[8] = '\0';
			}
			else if(config->algorithm_mode == DECRYPTION_MODE){
				algorithm_result = des_algorithm(message, config->algorithm_mode, key);
				cbc_pre_processed_message = cbc_pre_process(algorithm_result, previous_ciphertext);
				fwrite(cbc_pre_processed_message, sizeof(char), 8, config->output_file);
				strncpy((char*)previous_ciphertext, (char*)message, 8);
				previous_ciphertext[8] = '\0';
			}
			else {
				printf("Error! Invalid algorithm_mode!\n");
				return;
			}
			free(cbc_pre_processed_message);
			free(algorithm_result);
		}
	}
	else {
		printf("Error on run_cbc!\n");
		printf("Input file invalid!\n");
		return;
	}

	free(key);
	free(message);
}

unsigned char* read_key() {
	unsigned char* key = malloc(DES_KEY_BYTE_SIZE *  sizeof(char));
	FILE* key_file = fopen("keyfile", "rb");
	if(key_file) {
		fread(key, sizeof(char), DES_KEY_BYTE_SIZE, key_file);
		fclose(key_file);
	}
	else {
		printf("keyfile not found. Generating new key\n");
		key = generate_key(DES_KEY_BYTE_SIZE);
	}

	return key;
}

void process_final_message(unsigned char* message) {

}