#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "key_handler.h"

char* generate_key(int key_byte_size) {
  int i;
  char* key = (char*) malloc(key_byte_size * sizeof(char));
  FILE* key_file = fopen("keyfile", "wb");

  unsigned int seed = (unsigned int)time(NULL);
  srand (seed);

  if (!key_file) {
    printf("Problems opening the keyfile");
    return NULL;
  }

  for (i=0; i<key_byte_size; i++) {
    key[i] = rand()%255;
  }

  fwrite(key, 1, key_byte_size, key_file);
  fclose(key_file);

  return key;
}
