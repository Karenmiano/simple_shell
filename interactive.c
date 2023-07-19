#include "main.h"

void interactive()
{
	char *cmd = NULL;
	size_t len = 0;
	char **argv;
	pid_t child_pid;

	while (1)
                {
                        write(STDOUT_FILENO, "#cisfun$ ", 9);
                        if (getline(&cmd, &len, stdin) != -1)
                        {
                                cmd[_strchr(cmd, '\n')] = '\0';
                                argv = cmd_args(cmd);
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
                                        wait(NULL);
			}
                        free(cmd);
                        cmd = NULL;
                        free(argv);
                }
	return;
}
