#define MAX_ARGS 64

#ifndef SHELL_C
#define SHELL_C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>
extern char **environ;
char *trim_spaces(char *str);
char *get_path(char **env);

#endif

