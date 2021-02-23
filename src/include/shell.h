#ifndef SHELL_H
#define SHELL_H

#include "args.h"

struct shell_options {
  char* shell_lang;
  char* port;
  char* host;
};
typedef struct shell_options shell_options_t;

char* shell(options_t* args);
int type_shell(char* shell_lang);
void set_options(shell_options_t* options, options_t* args);

#endif