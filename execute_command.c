#include "shell.h"

/**
 * execute_command - Executes a command.
 * @argv: the pointer to an arg
 * @command: The command to execute.
 */
void execute_command(const char *command, char *argv[])
{
	char *path = getenv("PATH");
	char *token, *path_command;
	pid_t child_pid;
	int status;

	token = strok(path, ":");

	while (token != NULL)
	{
		path_command = create_path_command(token, command);
	if (access(command, X_OK) == 0)
	{
		execute_child_process(command, argv);
		free(path_command);
		return ();
	}
	free(path_command);
	token = strtok(NULL, ":");
	}
	display_command_not_found_error();
}
/**
 * create_path_command - Creates the full path command.
 * @path: The current path.
 * @command: The command.
 * Return: The full path command.
 */
char *create_path_command(const char *path, const char *command)
{
	size_t path_len = strlen(path);
	size_t command_len = strlen(command);
	char *path_command = malloc(path_len + command_len + 2);

	if (path_command == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(path_command, path);
	path_command[path_len] = '/';
	strcpy(path_command + path_len + 1, command);
	path_command[path_len + command_len + 1] = '\0';
	return (path_command);
}
/**
 * execute_child_process - Executes the command in a child process.
 * @argv: the pointer to an arg
 * @command: The command to execute.
 */
void execute_child_process(const char *command, char *argv[])
{
	pid_t child_pid;
	int status;

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
