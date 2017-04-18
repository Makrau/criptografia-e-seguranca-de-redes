#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

#include "binary_handler.h"

int main(int argc, char* argv[]) {

  usage();

  long a, b;
  char op;
  scanf("%ld %c %ld", &a, &op, &b);

  while((a < 0) || (a > 255) || (b < 0) || (b > 255)){
    usage();
    scanf("%ld %c %ld", &a, &op, &b);
  }

  if ((op == '+') || (op == '-')){
    printf("%ld\n", gf_xor(a, b));
  }
  else if (op == '*'){
    printf("%ld\n", gf_mult(a, b));
  }
  else if (op == '/'){
  }
  else
    printf("Unknown Operation\n");

  return 0;
}
