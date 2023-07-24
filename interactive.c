#include "main.h"
/**
 * interactive - displays interactive mode of shell
 * Return: nothing
 */
void interactive(void)
{
	char *cmd = NULL, **argv;
	size_t len = 0;
	pid_t child_pid;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (getline(&cmd, &len, stdin) != -1)
		{
			cmd[_strchr(cmd, '\n')] = '\0';
			if (check_builtin(&cmd) != 2)
				continue;
			argv = cmd_args(cmd);
			if (argv == NULL)
				continue;
			argv[0] = find(argv[0]);
			if (argv[0] != NULL)
			{
				child_pid = fork();
				if (child_pid == -1)
					perror("./hsh");
				else if (child_pid == 0)
				{
					execve(argv[0], argv, environ);
				}
				else
					wait(NULL);
			}
			else
				perror("./hsh");
		}
		else
		{
			free(cmd);
			write(STDOUT_FILENO, "\n", 1);
			exit(1);
		}
		free_mem(&cmd, argv);
	}
}
/**
 * _strcmp - compares two strings
 * @s1: string
 * @s2: string
 * Return: an int, 0 if they are similar, the difference of the different
 * characters if otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int j = 0;

	while (s1[j] == s2[j])
	{
		if (s1[j] == '\0')
		{
			return (0);
		}
		j++;
	}
	return (s1[j] - s2[j]);
}
/**
 * check_builtin - looks if command given is a built in command
 * @cmd: pointer to pointer to string storing command
 * Return: an int based on command executed
 */
int check_builtin(char **cmd)
{
	int i;
	built_in arr[] = {{"exit", exit_func}, {"env", print_env}};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(arr[i].command, *cmd) == 0)
		{
			free(*cmd);
			*cmd = NULL;
			arr[i].func_ptr();
			break;
		}
		i++;
	}
	return (i);
}
/**
 * free_mem - frees overall memory in loop for interactive mode
 * @cmd: pointer to pointer to string holding command
 * @argv: holds the array of command with its arguments
 * Return: nothing
 */
void free_mem(char **cmd, char **argv)
{
	free(*cmd);
	*cmd = NULL;
	free(argv[0]);
	free(argv);
}
