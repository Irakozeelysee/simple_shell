#include "shell.h"

/**
 * handle_errors - Handles errors in the shell.
 */

void handle_errors(void)
{
	if (ferror(stdin))
	{
		perror("stdin");
		exit(EXIT_FAILURE);
	}
}
