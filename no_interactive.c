#include "main.h"
/**
 * non_interactive - handles the non interactive form of the shell
 * Return: nothing
 */
void non_interactive(void)
{
	char *cmd = NULL, **argv;
	size_t len = 0;
	pid_t child_pid;

	while (getline(&cmd, &len, stdin) != -1)
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
		free(argv[0]);
		free(argv);
	}
	free(cmd);
}
