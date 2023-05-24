#include "shell.h"

/**
 * parse_pipeline - Parses a command into separate commands in a pipeline
 * @command: The command to parse
 * @pipeline: Array to store the separate commands
 * Return: The number of commands in the pipeline
 */
int parse_pipeline(const char *command, char **pipeline)
{
	char *token;
	char *command_copy = strdup(command);
	int num_cmds = 0;

	token = strtok(command_copy, "|");

	while (token != NULL && num_cmds < MAX_PIPELINE_SIZE)
	{
		pipeline[num_cmds++] = token;
		token = strtok(NULL, "|");
	}
	free(command_copy);
	return (num_cmds);
}
