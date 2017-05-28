#include "libusage.h"

void print_usage (FILE* stream, int exit_code, const char* program_name){
  fprintf (stream, "\nUsage:  %s [option] [param]\n", program_name);
  fprintf (stream,
           "  {-h  --help}                       Display this usage information.\n"
           "  {-d  --determine} [param]          Determine if a param is prime.\n"
           "                                                                    \n");
  exit (exit_code);
}


/* A string listing valid short options letters. */
const char* const short_options = "hd:";

/* An array describing valid long options. */
const struct option long_options[] = {
  { "help",       no_argument,        NULL, 'h' },
  { "determine",  required_argument,  NULL, 'd' },
  { NULL,         no_argument,        NULL, 0   }   /* Required at end of array. */
};

int next_option;

char *param = NULL;

int input_n;
