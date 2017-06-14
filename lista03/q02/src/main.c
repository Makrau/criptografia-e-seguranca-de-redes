#include "libusage.h"
#include "libmiller_rabin.h"

const char* program_name;

int main(int argc, char* argv[]) {

  program_name = argv[0];

  do {
    next_option = getopt_long(argc, argv, short_options, long_options, NULL);
    switch (next_option)
    {
      case 'h':   /* -h or --help */
        print_usage (stdout, 0, program_name);

      case 'n':   /* -n or --number */
        param = optarg;
        input_n = atoi(param);
        /* miller_rabin(input_n); */
        n_flag = 1;
        break;

      case 'k':   /* -k or --accuracy */
        param = optarg;
        input_k = atoi(param);
        /* miller_rabin(input_n); */
        k_flag = 1;
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

  if(argc == 1 || optind == 1 || n_flag == 0 || input_n > 2147483647 || input_n < 0){
    print_usage (stdout, 0, program_name);
    return 1;
  }

  if (is_prime(input_n, input_k)){
    printf("N=%d Is prime\n", input_n);
    probability(input_k);
  }
    else
      printf("N=%d Is Composite\n", input_n);

  return 0;
}
