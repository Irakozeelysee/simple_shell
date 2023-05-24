#include "shell.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
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
			command[custom_strcspn(command, "\n")] = '\0';
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
			line[custom_strcspn(line, "\n")] = '\0';
			execute_command(line);
		}
		fclose(file);
	}
	return (EXIT_SUCCESS);
}
