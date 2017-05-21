#ifndef ARGUMENTS_HANDLER_H
#define ARGUMENTS_HANDLER_H

#include "config.h"

#define VALID_ARGUMENTS 0
#define INVALID_ARGUMENTS 1
#define NUMBER_OF_ARGUMENTS 5
#define ENCRYPTION_MODE_ARGUMENT_POSITON 1
#define AES_KEY_SIZE_MODE_ARGUMENT_POSITION 2
#define INPUT_FILE_ARGUMENT_POSITION 3
#define OUTPUT_FILE_ARGUMENT_POSITION 4

int validate_arguments(int argc, char* argv[], config* config);
void invalid_number_of_arguments();
void tips();
void get_algorithm_mode(char* argv[], config* config, int* valid_arguments);
void get_key_size(char* argv[], config* config, int* valid_arguments);

#endif