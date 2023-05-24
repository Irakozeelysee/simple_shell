#include "shell.h"

/**
 * execute_pipeline - Executes a pipeline of commands connected by pipes
 * @pipeline: Array of commands in the pipeline
 * @num_cmds: Number of commands in the pipeline
 */
void execute_pipeline(char **pipeline, int num_cmds)
{
	int pipefd[MAX_PIPELINE_SIZE][2];
	pid_t pid;
	int i, status;
	int prev_pipe = 0;

	char *args[MAX_ARGS];
	int num_args = 0;
	char *envp[] = { NULL };

	for (i = 0; i < num_cmds; i++)
	{
		if (i < num_cmds - 1)
		{
			if (pipe(pipefd) == -1)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (i > 0)
			{
				if (dup2(prev_pipe, STDIN_FILENO) == -1)
				{
					perror("dup2");
					exit(EXIT_FAILURE);
				}
				close(prev_pipe);
			}
			if (i < num_cmds - 1)
			{
				if (dup2(pipefd[i][1], STDOUT_FILENO) == -1)
				{
					perror("dup2");
					exit(EXIT_FAILURE);
				}
				close(pipefd[i][1]);
			}		
			args[num_args] = strtok(pipeline[i], " \n");
			while (args[num_args] != NULL)
			{
				num_args++;
				args[num_args] = strtok(NULL, " \n");
			}
			args[num_args] = NULL;
		
			
			if (execve(args[0], args, envp) == -1)
			{
				perror("hsh");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (i > 0)
			{
				close(prev_pipe);
			}
			if (i < num_cmds - 1)
			{
				prev_pipe = pipefd[i][0];
				close(pipefd[1]);
			}
			if (wait(&status) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
	}
}
