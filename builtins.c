#include "main.h"

void exit_func()
{
	exit(0);
}
void print_env()
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return;
}
