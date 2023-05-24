#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

/**
 * display_prompt - displays the prompt that indicates where to start.
 * 
 * Return: void
 */
void display_prompt(void)
{
	printf("$ ");
}

/**
 * end_of_file - checks the end of the line Ctrl+D
 *
 * Return: void
 */
void end_of_file(void)
{
	printf("\n");
	exit(0);
}

/**
 * main - entry point of the program
 * 
 * Return: 0 on success
 */
int main(void)
{
	char command[100];
	char *args[100];
	int result;
	pid_t pid;
	int status;
	char *token;
	int i = 0;

	while (1)
	{
		display_prompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			end_of_file();
		}
		command[strcspn(command, "\n")] = '\0';
		token = strtok(command, " ");
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			result = execvp(args[0], args);
			if (result == -1)
			{
				printf("Command not found\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
