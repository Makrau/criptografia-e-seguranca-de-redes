#include "libusage.h"

void print_usage (FILE* stream, int exit_code, const char* program_name){
  fprintf (stream, "\nUsage:  %s [options]... [inputfile]...\n", program_name);
  fprintf (stream,
           "  {-h  --help}                       Display this usage information.\n"
           "  {-g  --generate}                   Generate a PRN.\n"
           "  {-f  --file} [inputfile]           Generate and put PRN in a file.\n"
           "                                                                    \n");
  exit (exit_code);
}


/* A string listing valid short options letters. */
const char* const short_options = "hgf:";

/* An array describing valid long options. */
const struct option long_options[] = {
  { "help",       no_argument,        NULL, 'h' },
  { "generate",   no_argument,        NULL, 'g' },
  { "file",       required_argument,  NULL, 'f' },
  { NULL,         no_argument,        NULL, 0   }   /* Required at end of array. */
};

int next_option;
