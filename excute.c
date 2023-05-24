#include "shell.h"

/**
 * execute_command - Executes the given command
 * @command: The command to execute
 */

void execute_command(char *command)
{
	pid_t pid;
	int status;

	char *args[MAX_ARGS];
	int num_args = 0;

	args[num_args] = strtok(command, " \n");
	while (args[num_args] != NULL)
	{
		num_args++;
		args[num_args] = strtok(NULL, " \n");
	}
	args[num_args] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *envp[] = { NULL };
		if (execve(args[0], args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
	}
}
