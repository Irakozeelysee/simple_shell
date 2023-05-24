#include "shell.h"

/**
 * custom_getline - Reads a line from the standard input
 * Return: The read line
 */

char *custom_getline(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t read;

	read = getline(&line, &line_size, stdin);
	if (read == -1)
	{
		end_of_file();
	}
	line[custom_strcspn(line, "\n")] = '\0';
	return (line);
}
