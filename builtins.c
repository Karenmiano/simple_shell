#include "main.h"
/**
 * exit_func - handles the exit built in command
 * Return: nothing
 */
void exit_func(void)
{
	exit(0);
}
/**
 * print_env - handles the env built in
 * Return: nothing
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
