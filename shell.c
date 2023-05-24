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
	if (argc == 1 && isatty(STDIN_FILENO))
	{
		char *command = NULL;
		size_t command_size = 0;
		char *pipeline[MAX_PIPELINE_SIZE];
		int num_cmds;
	
		while (1)
		{
			display_prompt();
			command = custom_getline();
			if (command == NULL)
			{
				break;
			}
			num_cmds = parse_pipeline(command, pipeline);
			if (num_cmds > 0)
			{
				execute_pipeline(pipeline, num_cmds);
			}
			free(command);
		}
	}
	else if (argc == 2)
	{
		FILE *file = fopen(argv[1], "r");
		char line[100];
		char *pipeline[MAX_PIPELINE_SIZE];
	
		if (file == NULL)
		{
			perror("Error opening file");
			return (EXIT_FAILURE);
		}
		while (fgets(line, sizeof(line), file) != NULL)
		{
			line[custom_strcspn(line, "\n")] = '\0';
			num_cmds = parse_pipeline(line, pipeline);
			if (num_cmds > 0)
			{
				execute_pipeline(pipeline, num_cmds);
			}
		}
		fclose(file);
	}
	display_prompt();
	return (EXIT_SUCCESS);
}
