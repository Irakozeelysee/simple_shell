#include "shell.h"

/**
 * main - Entry point of the shell program.
 * Return: Always 0.
 */
int main(void)
{
	char *command;
	char *argv[2];

	while (1)
	{
		display_prompt();
		command = read_command();
		execute_child_process(command, argv);
		handle_errors();
		free(command);
	}
	return (0);
}
