#ifndef USAGE_H
#define USAGE_H

/* Prints usage information for this program */
void print_usage (FILE* stream, int exit_code, const char* program_name);

/* A string listing valid short options letters. */
const char* const short_options = "he:d:";

/* An array describing valid long options. */
const struct option long_options[] = {
  { "help",     no_argument,       NULL, 'h' },
  { "encrypt",  required_argument, NULL, 'e' },
  { "decrypt",  required_argument, NULL, 'd' },
  { NULL,       no_argument,       NULL, 0   }   /* Required at end of array. */
};

/* Name of the file that indicate program input. */
const char* input_filename = NULL;

/* Name of the file to receive program output, or NULL for standard output. */
const char* output_filename = NULL;

int e_mode = 0;

int d_mode = 0;

int next_option;

#endif
