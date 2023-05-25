#include "shell.h"

/**
 * execute_command - Executes a command.
 * @command: The command to execute.
 */
void execute_command(const char *command)
{
	if (access(command, X_OK) == 0)
	{
		execute_child_process(command);
	}
	else
	{
		display_command_not_found_error();
	}
}
/**
 * execute_child_process - Executes the command in a child process.
 * @command: The command to execute.
 */
void execute_child_process(const char *command)
{
	char *argv[2];
	pid_t child_pid;
	int status;

	argv[0] = (char *)command;
	argv[1] = NULL;

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

/**
 * display_command_not_found_error - Displays
 * the "command not found" error.
 */
void display_command_not_found_error(void)
{
	const char *error_message = "hsh: No such file or directory\n";
	size_t message_length = strlen(error_message);
	ssize_t write_count;

	write_count = write(STDERR_FILENO, error_message, message_length);
	(void)write_count;
}
