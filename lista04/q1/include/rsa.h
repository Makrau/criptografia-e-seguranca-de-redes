#ifndef RSA_H
#define RSA_H

#include "config.h"

void get_additional_data(config* config);
void get_private_key(config* config);
void get_algorithm_mode(config* config);
void get_input_path(config* config);
void print_algorithm_modes();

#endif