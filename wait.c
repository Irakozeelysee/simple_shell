#include "shell.h"
/**
 * wait_child_process - waits a child program to process
 * return:
 */

void wait_child_process(void)
{
	int status;

	pid_t pid = wait(&status);

	if (pid == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}
}
