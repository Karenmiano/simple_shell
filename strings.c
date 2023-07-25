#include "main.h"
/**
 * _strncmp - checks if the first n characters of two strings are
 * the same
 * @s1: string
 * @s2: string
 * @n: number of characters to be checked
 * Return: 0 if they are equal, difference between the first unsimilar
 * characters if otherwise
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int j = 0;

	while (s1[j] == s2[j])
	{
		if (s1[j] == '\0' || j == n - 1)
		{
			return (0);
		}
		j++;
	}
	return (s1[j] - s2[j]);
}
/**
 * _strlen - finds the length of a string
 * @s: address of the string
 * Return: lenth of the string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strdup - stores a copy of a string in memory
 * @str: the string to read from
 * Return: pointer to the copy
 */
char *_strdup(char *str)
{
	char *strr;
	int i = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	i += 1;
	strr = malloc(i);
	if (strr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		strr[i] = str[i];
		i++;
	}
	strr[i] = '\0';
	return (strr);
}
