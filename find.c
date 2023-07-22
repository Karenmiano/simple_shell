#include "main.h"

char *find(char *f)
{
	char *s, *token, *found = NULL;
	path_dir *head = NULL, *trav;
	struct stat st;

	if (stat(f, &st) == 0)
		return (_strdup(f));
	s = _strdup(_getenv("PATH"));
	if (s == NULL)
		return (NULL);
	token = strtok(s, ":");
	while (token != NULL)
	{
		add_node_end(&head, concat(token, f));
		token = strtok(NULL, ":");
	}
	trav = head;
	while (trav != NULL)
	{
		if (stat(trav->full_path, &st) == 0)
		{
			found = _strdup(trav->full_path);
			break;
		}
		trav = trav->next;
	}
	free_list(head);
	free(s);
	return (found);
}
char *_getenv(const char *name)
{
	int i = 0;
	char *s;

	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			s = environ[i];
			while (*s != '=')
				s++;
			return (++s);
		}
		i++;
	}
	return (NULL);
}
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
path_dir *add_node_end(path_dir **head, char *str)
{
	path_dir *end;
	path_dir *trav;

	end = malloc(sizeof(path_dir));
	if (end == NULL)
		return (NULL);
	end->full_path = str;
	end->next = NULL;
	trav = *head;
	if (trav == NULL)
		*head = end;
	else
	{
		while (trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = end;
	}
	return (end);
}
/**
 * str_concat - concatenates two strings and stores the copy
 * @s1: string
 * @s2: string
 * Return: pointer to the copy
 */
char *concat(char *s1, char *s2)
{
	char *temp, *str;
	int i = 1;

	if (s1 == NULL)
		s1 = "\0";
	if (s2 == NULL)
		s2 = "\0";
	temp = s1;
	while (*temp != '\0')
	{
		i++;
		temp++;
	}
	temp = s2;
	while (*temp != '\0')
	{
		i++;
		temp++;
	}
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	str[i] = '/';
	i++;
	while (*s2 != '\0')
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
/**
 * free_list - frees memory of a singly linked list
 * @head: pointer to head node
 * Return: nothing
 */
void free_list(path_dir *head)
{
	path_dir *p, *t;

	p = head;
	while (p != NULL)
	{
		t = p;
		p = t->next;
		free(t->full_path);
		free(t);
	}
}
