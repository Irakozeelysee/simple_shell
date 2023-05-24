#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#define MAX_ARGS 10

void display_prompt(void);
void end_of_file(void);
void execute_pipeline(char **pipeline, int num_cmds);
size_t custom_strcspn(const char *str, const char *reject);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int execve(const char *pathname, char *const argv[], char *const envp[]);
char *custom_getline(void);
void wait_child_process(void);
void change_directory(char **args);
void print_working_directory(void);
void echo_command(char **args);
void execute_command(char **args, char *input_file, char *output_file);
int parse_pipeline(const char *command, char **pipeline);
int redirect_input(const char *file);
int redirect_output(const char *file);

#endif /* SHELL_H */
