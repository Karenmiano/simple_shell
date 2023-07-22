#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
char *_getenv(const char *name);
int _strncmp(const char *s1, const char *s2, int n);
int _strlen(const char *s);
extern char **environ;
char *_strdup(char *str);
typedef struct p
{
        char *full_path;
        struct p *next;
} path_dir;
typedef struct built_in
{
	char *command;
	void (*func_ptr)();
} built_in;
int _strcmp(char *s1, char *s2);
char *concat(char *s1, char *s2);
path_dir *add_node_end(path_dir **head, char *str);
int _strchr(char *s, char c);
char **cmd_args(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void non_interactive();
void interactive();
char *find(char *f);
void exit_func();
void print_env();
void free_list(path_dir *head);
#endif
