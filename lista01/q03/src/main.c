#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

#include "binary_handler.h"

int main(int argc, char* argv[]) {

  usage();

  long a, b;
  char op;
  scanf("%ld %ld %c", &a, &b, &op);

  while((a < 0) || (a > 255) || (b < 0) || (b > 255)){
    usage();
    scanf("%ld %ld %c", &a, &b, &op);
  }

  if ((op == '+') || (op == '-')){
    printf("%ld\n", gf_xor(a, b));
  }
  else if (op == '*'){
  }
  else if (op == '/'){
  }
  else
    printf("Unknown Operation\n");

  return 0;
}
