#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * display_prompt - displays the prompt that indicates where to start.
 * 
 * Return: nothing
 */
void display_prompt()
{
	printf ("$");
}

/**
 * end_of_file - checks the end of the line Ctrl+D
 *
 * Return: 0 successful.
 */
void end_of_file ()
{
	printf ("\n");
	exit(0);
}
void test1()
{
}

/**
 * main - starting point
 *
 * Return:
 */
int main ()
{
	char command[100];
	int result;

	while (1)
	{
		display_prompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			end_of_file();
		}
		command[strcspn(command, "\n")] = '\0';

		result = execlp(command, command, NULL);
		if (result == -1)
		{
			printf("Command not found\n");
		}
	}
	return (0);
}
