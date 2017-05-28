#include "libtruerand.h"

unsigned long long int true_rand_number(unsigned long long int p){

  int min = 2; //because 1 < a < p - 1
  unsigned long long int max = p - 1;
  unsigned long long int random_value;
  FILE *fd;

  assert (max > min);

  fd = fopen("/dev/urandom", "r");
  fread(&random_value, sizeof(random_value), 1, fd);
  fclose(fd);

  return min + (random_value % (max - min + 1));
}
