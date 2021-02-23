#include <stdio.h>
#include <stdlib.h>

#include "args.h"
#include "colors.h"
#include "shell.h"

int main(int argc, char* argv[]) {
  options_t options;
  options_parser(argc, argv, &options);
  char* payload = shell(&options);

  printf("%s\n", payload);
  free(payload);
  return EXIT_SUCCESS;
}
