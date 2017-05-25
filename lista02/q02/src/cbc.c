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
	unsigned char* message = malloc(9 * sizeof(char));
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
			message[bytes_read] = '\0';
			
			if(feof(config->input_file)){
				if(bytes_read == 0) {
					return;
				}
				if(bytes_read != 8) {
					message = append_plaintext(message);
				}
				fclose(config->input_file);
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
		fclose(config->output_file);

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

unsigned char *append_plaintext(unsigned char* plaintext){
  int plaintext_size, mod, i;
  plaintext_size = strlen((char*)plaintext);
  mod = DES_BLOCK_BYTE_SIZE - (plaintext_size % DES_BLOCK_BYTE_SIZE);
  // printf("message to be appended: %s\n", plaintext);
  // printf("size: %d\n", plaintext_size); 
  // printf("mod: %d\n", mod); 
  if(mod == DES_BLOCK_BYTE_SIZE){
  	//printf("not appending...\n");
    return plaintext;
  }
  else{
    plaintext = (unsigned char *) realloc(plaintext, (plaintext_size+mod) * sizeof(char));
    if(plaintext == NULL){
      printf("Sem espaço suficiente\n");
      return NULL;
    }
    for(i = plaintext_size; i < plaintext_size + mod; ++i){
      plaintext[i] = '*';
    }
    plaintext[i] = '\0';
    plaintext_size = strlen((char*)plaintext);
    //printf("plaintext final size: %d\n", plaintext_size); 
    return plaintext;
  }
}