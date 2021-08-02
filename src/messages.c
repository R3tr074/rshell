#include "messages.h"

#include <stdio.h>
#include <stdlib.h>

#include "colors.h"

void help() {
  fprintf(stdout, BLUE __PROGRAM_NAME__ "\n\n" NO_COLOR);
  usage();
  options();
  author();
  version();
}

void usage() {
  fprintf(stdout, BROWN "Usage: " NO_COLOR);
  fprintf(stdout, "%s [options]\n", __PROGRAM_NAME__);
  fprintf(stdout, "run:\nexport RHOST=<host> \nor \nexport RPORT=<port>\n");
  fprintf(stdout, "To automatic set host and/or port\n");
}

void options() {
  fprintf(stdout, BROWN "Options:\n" NO_COLOR);
  fprintf(stdout, GRAY "\t-v|--version\n" NO_COLOR "\t\tPrints %s version\n\n",
          __PROGRAM_NAME__);
  fprintf(stdout,
          GRAY "\t-h|--help\n" NO_COLOR "\t\tPrints this help message\n\n");
  fprintf(stdout, GRAY "\t-l|--lang\n" NO_COLOR "\t\tSet shell lang\n\n");
  fprintf(stdout, GRAY "\t-p|--port\n" NO_COLOR "\t\tSet shell port\n\n");
  fprintf(stdout, GRAY "\t-H|--host\n" NO_COLOR "\t\tSet shell host\n\n");
}

void author() {
  fprintf(stdout, BROWN "Written by: " GRAY "%s\n" NO_COLOR,
          __PROGRAM_AUTHOR__);
}

void version() {
  fprintf(stdout, __PROGRAM_NAME__ " version: " GRAY "%s\n" NO_COLOR,
          __PROGRAM_VERSION__);
}
