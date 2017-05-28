#include "libusage.h"
#include "libtruerand.h"

const char* program_name;

int main(int argc, char* argv[]) {

  program_name = argv[0];

  int *key, key_size = 10;
  key = generate_key(key_size);

  do {
    next_option = getopt_long(argc, argv, short_options, long_options, NULL);
    switch (next_option)
    {
      case 'h':   /* -h or --help */
        print_usage (stdout, 0, program_name);

      case 'g':   /* -g or --generate */
        break;

      case 'f':   /* -f or --file */
        /* This option takes an argument, the name of the output file.  */
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

  return 0;
}
