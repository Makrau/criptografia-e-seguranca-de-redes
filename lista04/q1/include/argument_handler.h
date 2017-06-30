#ifndef ARGUMENT_HANDLER_H
#define ARGUMENT_HANDLER_H

#include "config.h"

#define PRIME_P 1
#define PRIME_Q 2
#define PUBLIC_KEY_E 3

int verify_arguments(int argc, char* argv[], config* config);
int verify_public_key(int public_key_e, config* config);
void arguments_description();

#endif