#ifndef ARGUMENT_HANDLER_H
#define ARGUMENT_HANDLER_H

#define INVALID 0
#define VALID 1
#define MIN_ARGUMENTS 4
#define A_POSITION 1
#define B_POSITION 2
#define P_POSITION 3

#include "config.h"

int verify_arguments(int argc, char* argv[], config* config);
void print_arguments_message();

#endif