#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"
#include "build_shell.h"
#include "colors.h"
#include "error.h"

char* shell(options_t* args) {
  shell_options_t options;
  set_options(&options, args);
  char* payload = valloc(sizeof(char));

  switch (type_shell(options.shell_lang)) {
    case 'b':  // bash
      return bash(payload, options);
      break;

    case 'p':  // python
      return python(payload, options);
      break;

    case 'l':  // perl
      return perl(payload, options);
      break;

    case 'h':  // php
      return php(payload, options);
      break;

    case 'r':  // ruby
      return ruby(payload, options);
      break;

    case 'n':  // netcat
      return netcat(payload, options);
      break;

    case 'j':  // java
      return java(payload, options);
      break;

    default:
      fprintf(stderr,
              "invalid shell format, try \"" BLUE "bash" NO_COLOR "\"\n");
      exit(EXIT_FAILURE);
      break;
  }
}

int type_shell(char* shell_lang) {
  if (strcmp("bash", shell_lang) == 0) {
    return 'b';
  } else if (strcmp("python", shell_lang) == 0 ||
             strcmp("python2", shell_lang) == 0 ||
             strcmp("python3", shell_lang) == 0 ||
             strcmp("py", shell_lang) == 0) {
    return 'p';
  } else if (strcmp("perl", shell_lang) == 0) {
    return 'l';
  } else if (strcmp("php", shell_lang) == 0) {
    return 'h';
  } else if (strcmp("ruby", shell_lang) == 0) {
    return 'r';
  } else if (strcmp("nc", shell_lang) == 0 ||
             strcmp("netcat", shell_lang) == 0) {
    return 'n';
  } else if (strcmp("java", shell_lang) == 0) {
    return 'j';
  } else {
    return '?';
  }
}

void set_options(shell_options_t* options, options_t* args) {
  options->host = args->host;
  options->port = args->port;
  options->shell_lang = args->sh;
}