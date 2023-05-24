#include "shell.h"

/**
 * read_command - Reads a command from the user.
 *
 * Return: The command entered by the user.
 */

char *read_command(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t bytes_read;
	
	bytes_read = getline(&command, &bufsize, stdin);
	if (bytes_read == -1)
	{
		if (feof(stdin))
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	command[bytes_read - 1] = '\0';
	return (command);
}
