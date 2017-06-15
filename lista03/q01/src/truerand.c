#include "libtruerand.h"

int true_rand_number(){

  static int dev_random_fd = -1;
  int min = 0;
  int max = INT_MAX;

  char* next_random_byte;
  int bytes_to_read;
  unsigned random_value;

  assert (max > min);

  if (dev_random_fd == -1) {
    dev_random_fd = open ("/dev/random", O_RDONLY);
    assert (dev_random_fd != -1);
  }

  next_random_byte = (char*) &random_value;
  bytes_to_read = sizeof (random_value);

  do {
    int bytes_read;
    bytes_read = read (dev_random_fd, next_random_byte, bytes_to_read);
    bytes_to_read -= bytes_read;
    next_random_byte += bytes_read;
  } while (bytes_to_read > 0);

  return min + (random_value % (max - min + 1));
}

int *generate_key(int key_size){
  int *key = (int*) malloc((key_size + 2) * sizeof(int));
  int i;
  for(i = 0; i < key_size; i++){
    key[i] = true_rand_number();
  }

  key[i] = '\n';
  key[i+1] = '\0';
  
  return key;
}
