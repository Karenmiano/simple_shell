#include "main.h"

void non_interactive()
{
	char *cmd = NULL;
	size_t len = 0;
	pid_t child_pid;
	char **argv;
	int i;
	built_in arr[] = {{"exit", exit_func}, {"env", print_env}};

	while (getline(&cmd, &len,stdin) != -1)
	{
		cmd[_strchr(cmd, '\n')] = '\0';
		argv = cmd_args(cmd);
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
		argv[0] = find(argv[0]);
		if (argv[0] != 	NULL)
		{
			child_pid = fork();
			if (child_pid == -1)
				perror("./hsh");
			else if (child_pid == 0)
			{
				execve(argv[0], argv, environ);
				perror("./hsh");
				free(argv);
				free(cmd);
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(NULL);
			}
		}
		else
			perror("./hsh");
		free(argv[0]);
		free(argv);
	}
	free(cmd);
	return;
}
