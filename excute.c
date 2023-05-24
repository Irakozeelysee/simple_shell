#include "shell.h"

/**
 * execute_command - Executes the given command
 * @command: The command to execute
 */

void execute_command(char *command)
{
	pid_t pid;
	int status;

	char *args[2];

	args[0] = command;
	args[1] = "NULL";

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
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
