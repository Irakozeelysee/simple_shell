#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		char command[100];
	
		while (1)
		{
			display_prompt();
			if (fgets(command, sizeof(command), stdin) == NULL)
			{
				end_of_file();
			}
			execute_command(command);
		}
	}
	else if (argc == 2)
	{
		FILE *file = fopen(argv[1], "r");
		char line[100];

		if (file == NULL)
		{
			perror("Error opening file");
			return (EXIT_FAILURE);
		}
		while (fgets(line, sizeof(line), file) != NULL)
		{
			execute_command(line);
		}
		fclose(file);
	}
	return (EXIT_SUCCESS);
}
