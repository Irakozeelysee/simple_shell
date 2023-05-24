#include "shell.h"

/**
 * execute_command - Executes a command.
 * @command: The command to execute.
 */
void execute_command(const char *command)
{
	char error_message[100] = "";
	ssize_t write_count;
	size_t error_message_length = 0;
	const char *not_found_message = ": command not found\n";
	char *argv[2];
	pid_t child_pid;
	int status;

	argv[0] = (char *)command;
	argv[1] = NULL;

	if (access(command, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			_exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(command, argv, environ) == -1)
			{
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	else
	{
		const char *ptr = command;
		while (*ptr)
		{
			error_message[error_message_length] = *ptr;
			error_message_length++;
			ptr++;
		}
		ptr = not_found_message;
		while (*ptr && error_message_length < sizeof(error_message) - 1)
		{
			error_message[error_message_length] = *ptr;
			error_message_length++;
			ptr++;
		}
		write_count = write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
		(void)write_count;
	}
}
