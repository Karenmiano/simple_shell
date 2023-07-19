#include <stdio.h>
#include "main.h"
/**
 * main - starting point, determines whether program is interactive
 * or non interactive
 * Return: 0 if successful
 */
int main(void)
{
	int piped;

	piped = !isatty(STDIN_FILENO);
	if (piped)
	{
		non_interactive();
	}
	else
	{
		interactive();
	}
	return (0);
}
/**
 * _strchr - locates a character in a string
 * @s: address of the string
 * @c: the character to be searched
 * Return: index of character if found -1 if otherwise
 */
int _strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
