#include "main.h"
/**
 * find - will check if command's executable exists
 * @f: the command
 * Return: absolute path of command, NULL if command doesn't exist
 */
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
/**
 * _getenv - finds the value of an environment variable
 * @name: the environment variable
 * Return: a string carrying the value
 */
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
/**
 * add_node_end - adds a node at end of linked list progressively built
 * @head: pointer to pointer to head node
 * @str: string containing to be examined full path of command
 * Return: new node created
 */
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
 * concat - concatenates the directory paths with commands and stores
 * a copy
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
