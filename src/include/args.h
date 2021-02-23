#ifndef ARGS_H
#define ARGS_H

#include <getopt.h>
#include <stdbool.h>

struct options {
  bool help;
  bool version;
  char* sh;
  char* port;
  char* host;
};

typedef struct options options_t;

void options_parser(int argc, char* argv[], options_t* options);

#endif