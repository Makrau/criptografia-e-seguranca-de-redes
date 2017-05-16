#ifndef _DES_H_
#define _DES_H_

#define ENCRYPT_MODE 1
#define DECRYPT_MODE 0
#define KEY_CHAR_SIZE 8
#define BYTE_SIZE 8
#define PC1_SIZE 56
#define KEY_BIT_SIZE 48
#define KEY_C_D_AMOUNT 17
#define C_D_SIZE 28
#define FIRST_SUB_KEY 1
#define HALF_BLOCK_SIZE 32
#define EXPANDED_BLOCK_SIZE 48
#define S_AMOUNT 8
#define S_BIT_GROUP 6
#define S_OUTPUT_SIZE 4

typedef struct {
	unsigned char key[KEY_BIT_SIZE + 1];
	unsigned char c[C_D_SIZE + 1];
	unsigned char d[C_D_SIZE + 1];
} key_structure;

typedef struct {
	unsigned char left_block[HALF_BLOCK_SIZE + 1];
	unsigned char right_block[HALF_BLOCK_SIZE + 1];
}block_structure;

unsigned char* generate_key();
unsigned char* generate_binary_key_string(unsigned char* key);
unsigned char* generate_binary_message_string(unsigned char* message);
unsigned char* pc1_function(unsigned char* key_string);
key_structure* generate_sub_keys(unsigned char* key_string);
void make_key_rounds(key_structure* sub_keys, int round);
void make_half_block_rounds(block_structure* blocks, key_structure* sub_keys, int round);
unsigned char* encrypt_message(unsigned char* message, key_structure* sub_keys);
unsigned char* decrypt_message(unsigned char* message, key_structure* sub_keys);
unsigned char* ip_function(unsigned char* message);
unsigned char* f_function(unsigned char* right_block, unsigned char* key);
unsigned char* expansion_function(unsigned char* right_block);
int find_s_value(int counter, int i, int j);
unsigned char* s_box_function(unsigned char* input);
unsigned char* p_function(unsigned char* s_string);
unsigned char* final_permutation(unsigned char* pre_output);
key_structure* make_inverse_sub_keys(key_structure* sub_keys);
void write_sample_message();

#endif