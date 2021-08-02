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
  fprintf(stdout, MAGENTA "\t-v|--version\n" NO_COLOR "\t\tPrints %s version\n\n",
          __PROGRAM_NAME__);
  fprintf(stdout,
          MAGENTA "\t-h| --help\n" NO_COLOR "\t\tPrints this help message\n\n");
  fprintf(stdout, MAGENTA "\t-l| --lang\n" NO_COLOR "\t\tSet shell lang\n\n");
  fprintf(stdout, MAGENTA "\t-p| --port\n" NO_COLOR "\t\tSet shell port\n\n");
  fprintf(stdout, MAGENTA "\t-H| --host\n" NO_COLOR "\t\tSet shell host\n\n");
  fprintf(stdout, MAGENTA "\t-s| --shell\n" NO_COLOR "\t\tShow all shell types\n\n");
}

void shell_types() {
  fprintf(stdout, "All shell types:\n");
  puts(BLUE "  bash" NO_COLOR);
  puts(BLUE "  python" NO_COLOR);
  puts(BLUE "  perl" NO_COLOR);
  puts(BLUE "  ruby" NO_COLOR);
  puts(BLUE "  netcat " GRAY "// with mkfifo" NO_COLOR);
  puts(BLUE "  java" NO_COLOR);
}

void author() {
  fprintf(stdout, BROWN "Written by: " GRAY "%s\n" NO_COLOR,
          __PROGRAM_AUTHOR__);
}

void version() {
  fprintf(stdout, __PROGRAM_NAME__ " version: " GRAY "%s\n" NO_COLOR,
          __PROGRAM_VERSION__);
}
