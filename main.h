#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
extern char **environ;
int _strchr(char *s, char c);
char **cmd_args(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void non_interactive();
void interactive();

#endif
