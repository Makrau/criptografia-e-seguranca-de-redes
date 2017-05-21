#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <fcntl.h>

#include "galois_arithmetic.h"
#include "usage.h"

const char* program_name;

int main(int argc, char* argv[]) {

  program_name = argv[0];

  do {
    next_option = getopt_long(argc, argv, short_options, long_options, NULL);
    switch (next_option)
    {
      case 'h':   /* -h or --help */
        print_usage (stdout, 0, program_name);

      case 'e':   /* -e or --encrypt */
        /* This option takes an argument, the name of the output file.  */
        e_mode = 1;
        input_filename = optarg;
        output_filename = "encrypted_message";
        break;

      case 'd':   /* -d or --decrypt */
        d_mode = 1;
        input_filename = optarg;
        output_filename = "decrypted_message";
        break;

      case '?':   /* The user specified an invalid option.  */
        print_usage (stderr, 1, program_name);

      case -1:    /* All options processed.  */
        break;

      default:    /* Something else: unexpected.  */
        exit(1);
    }
  }
  while (next_option != -1);

  if(argc == 1 || optind == 1){
    print_usage (stdout, 0, program_name);
    return 1;
  }

  int fd = open("teste.txt", O_WRONLY | O_APPEND);
  printf("%d\n", fd);
  write(fd, "teste", 100);

  return 0;
}
