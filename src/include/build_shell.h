#ifndef BUILD_SHELL_H
#define BUILD_SHELL_H
#include "shell.h"

char* bash(char* payload, shell_options_t options);
char* python(char* payload, shell_options_t options);
char* perl(char* payload, shell_options_t options);
char* php(char* payload, shell_options_t options);
char* ruby(char* payload, shell_options_t options);
char* netcat(char* payload, shell_options_t options);
char* java(char* payload, shell_options_t options);
#endif