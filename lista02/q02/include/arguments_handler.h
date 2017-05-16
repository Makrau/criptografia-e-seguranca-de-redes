#ifndef ARGUMENTS_HANDLER_H
#define ARGUMENTS_HANDLER_H

#include "des.h"

#define VALID_ARGUMENTS 0
#define INVALID_ARGUMENTS 1
#define NUMBER_OF_ARGUMENTS 4
#define ENCRYPTION_MODE_ARGUMENT_POSITON 1
#define INPUT_FILE_ARGUMENT_POSITION 2
#define OUTPUT_FILE_ARGUMENT_POSITION 3

int validate_arguments(int argc, char* argv[], des_config* config);
void invalid_number_of_arguments();
void tips();
void get_algorithm_mode(char* argv[], des_config* config, int* valid_arguments);
void get_input_and_output_files(char* argv[], des_config* config, int* valid_arguments);

#endif