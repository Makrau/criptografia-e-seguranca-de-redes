#ifndef LIBUSAGE_H
#define LIBUSAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/* Prints usage information for this program */
void print_usage (FILE* stream, int exit_code, const char* program_name);

/* A string listing valid short options letters. */
extern const char* const short_options;

/* An array describing valid long options. */
extern const struct option long_options[];

extern int next_option;

#endif
