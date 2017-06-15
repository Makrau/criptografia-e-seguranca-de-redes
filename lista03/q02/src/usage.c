#include "libusage.h"

void print_usage (FILE* stream, int exit_code, const char* program_name){
  fprintf (stream, "\nUsage:  %s -[option] [param] ...\n", program_name);
  fprintf (stream,
           "  {-h  --help}                       Display this usage information.\n"
           "  {-n  --number} [number]             A number < 2147483647 to be determined if is prime.\n"
           "  {-k  --accuracy} [rounds]           The result accuracy desired.\n"
           "                                         Default values is 10 rounds.\n"
           "                                                                    \n");
  exit (exit_code);
}


/* A string listing valid short options letters. */
const char* const short_options = "hn:k:";

/* An array describing valid long options. */
const struct option long_options[] = {
  { "help",       no_argument,        NULL, 'h' },
  { "number",     required_argument,  NULL, 'n' },
  { "accuracy",   required_argument,  NULL, 'k' },
  { NULL,         no_argument,        NULL, 0   }   /* Required at end of array. */
};

int next_option;

char *param = NULL;

unsigned long long int input_n;

int input_k = 10;

int n_flag = 0;

int k_flag = 0;
