#include "args.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "messages.h"

static void set_default_options(options_t *options) {
  char *envPort = getenv("RPORT");
  char *envHost = getenv("RHOST");

  options->help = false;
  options->version = false;
  options->sh = "bash";

  if (envPort == NULL) {
    options->port = "1111";
  } else {
    options->port = envPort;
  }
  if (envHost == NULL) {
    options->host = "127.0.0.1";
  } else {
    options->host = envHost;
  }
}

void switch_options(int arg, char *optarg, options_t *options) {
  switch (arg) {
    case 'h':
      options->help = true;
      help();
      exit(EXIT_SUCCESS);
      break;

    case 'v':
      options->version = true;
      version();
      exit(EXIT_SUCCESS);
      break;

    case 's':
      shell_types();
      exit(EXIT_SUCCESS);
      break;

    case 'H':
      options->host = optarg;
      break;

    case 'p':
      options->port = optarg;
      break;

    case 'l':
      options->sh = optarg;
      break;

    default:
      exit(EXIT_FAILURE);
      break;
  }
}

void options_parser(int argc, char *argv[], options_t *options) {
  set_default_options(options);

  int arg;

  static struct option long_options[] = {
      {"help", no_argument, 0, 'h'},        {"version", no_argument, 0, 'v'},
      {"host", required_argument, 0, 'H'},  {"port", required_argument, 0, 'p'},
      {"lang", required_argument, 0, 'l'},
  };

  while (true) {
    int option_index = 0;
    arg = getopt_long(argc, argv, "hvsH:p:l:", long_options, &option_index);

    if (arg == -1) break;

    switch_options(arg, optarg, options);
  }
}
