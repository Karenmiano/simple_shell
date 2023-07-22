#include "main.h"

void interactive()
{
	char *cmd = NULL;
	size_t len = 0;
	char **argv;
	pid_t child_pid;
	int i;
	built_in arr[] = {{"exit", exit_func}, {"env", print_env}};

	while (1)
                {
                        write(STDOUT_FILENO, "#cisfun$ ", 9);
                        if (getline(&cmd, &len, stdin) != -1)
                        {
                                cmd[_strchr(cmd, '\n')] = '\0';
				for (i = 0; i < 2; i++)
				{
					if (_strcmp(arr[i].command, cmd) == 0)
					{
						free(cmd);
						cmd = NULL;
						arr[i].func_ptr();
						break;
					}
					i++;
				}
				if (i != 2)
					continue;
                                argv = cmd_args(cmd);
				argv[0] = find(argv[0]);
				if (argv[0] != NULL)
				{
                                	child_pid = fork();
                                	if (child_pid == -1)
                                        	perror("./hsh");
                                	else if (child_pid == 0)
                                	{
                                        	execve(argv[0], argv, environ);
                                        	perror("./hsh");
						free(argv[0]);
						free(argv);
						free(cmd);
                                        	exit(EXIT_FAILURE);
                                	}
                                	else
                                        	wait(NULL);
				}
				else
					perror("./hsh");
			}
			else
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(1);
			}
                        free(cmd);
                        cmd = NULL;
			free(argv[0]);
                        free(argv);
                }
	return;
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
