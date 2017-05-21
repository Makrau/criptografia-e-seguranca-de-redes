#ifndef BINARY_HANDLER_H
#define BINARY_HANDLER_H

#define DES_MESSAGES_BIT_SIZE 64
#define CHAR_BIT_SIZE 8

unsigned char* translate_char_to_binary_string(char input);
unsigned int translate_binary_string_to_int(char* input);
unsigned char* string_xor(unsigned char* word1, unsigned char* word2);
unsigned char* generate_binary_message_string(unsigned char* message);

#endif