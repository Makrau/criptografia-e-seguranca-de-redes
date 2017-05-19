#include <stdlib.h>

#include "cbc.h"
#include "binary_handler.h"
#include "key_handler.h"
#include "des.h"

unsigned char initialization_vector[8] = "InitVect";

unsigned char* process_first_block(unsigned char* first_block_message) {
	unsigned char* first_message_processed = malloc(CHAR_BIT_SIZE * sizeof(char) + 1);
	int i = 0;
	for(i = 0; i < 9; i++) {
		first_message_processed[i] = (first_block_message[i] ^ initialization_vector[i]);
	}

	first_message_processed[9] = '\0';

	return first_message_processed;
}

void run_cbc(config* config) {
	unsigned char* message = malloc(8 * sizeof(char));
	unsigned char* key;
	unsigned char* algorithm_result;
	int flag = 1;

	//Searching for keyfile. If not found, generate a new key.
	key = read_key();

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
			algorithm_result = des_algorithm(message, config->algorithm_mode, key);
			fwrite(algorithm_result, sizeof(char), 8, config->output_file);
		}
		
	}
	else {
		printf("Error on run_cbc!\n");
		printf("Input file invalid!\n");
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