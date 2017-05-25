#include <stdio.h>
#include <stdlib.h>

void print_usage (FILE* stream, int exit_code, const char* program_name){
  fprintf (stream, "\nUsage:  %s [options]... [inputfile]...\n", program_name);
  fprintf (stream,
           "  {-h  --help}                       Display this usage information.\n"
           "  {-e  --encrypt} [inputfile]        Encrypt a plaintext using AES.\n"
           "  {-d  --decrypt} [inputfile]        Decrypt a ciphertext using AES.\n"
           "                                                                    \n");
  exit (exit_code);
}
