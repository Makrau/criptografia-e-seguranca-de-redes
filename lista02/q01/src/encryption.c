#include "file_manipulate.h"
#include <string.h>
#include <stdio.h>

void encrypt(char *input_filename, char *key){
  char *plaintext = read_from_file(input_filename);
  plaintext = append_plaintext(plaintext);
}
