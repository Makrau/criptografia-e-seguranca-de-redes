#include <stdio.h>
#include <stdlib.h>

#include "binary_handler.h"

int main(int argc, char* argv[]) {

  usage();

  char op;
  long a, b;
  scanf("%ld %ld %c", &a, &b, &op);

  if ((op == '+') || (op == '-')){
    printf("%ld\n", gf_xor(a, b));
  }
  else if (op == 'b'){
  }

  return 0;
}
