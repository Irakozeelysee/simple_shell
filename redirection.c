#include "shell.h"

/**
 * redirect_input - Redirects the standard input to a file
 * @file: The name of the file to redirect input from
 * Return: 0 on success, -1 on failure
 */
int redirect_input(const char *file)
{
	int fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

/**
 * redirect_output - Redirects the standard output to a file
 * @file: The name of the file to redirect output to
 * Return: 0 on success, -1 on failure
 */
int redirect_output(const char *file)
{
	int fd = open(file, O_WRONLY | O_CREAT
			| O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
