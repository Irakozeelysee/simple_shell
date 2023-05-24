#include "shell.h"

/**
 * end_of_file - Checks the end of the line Ctrl+D
 */

void end_of_file(void)
{
	char *message = "\n";
	int length = 0;

	while (message[length] != '\0')
		length++;
	write(STDOUT_FILENO, message, length);
	exit(EXIT_SUCCESS);
}
