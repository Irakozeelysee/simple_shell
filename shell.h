#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

extern char error_message[100];
extern ssize_t write_count;
extern size_t error_message_length;
extern const char *not_found_message;
extern char *argv[2];
extern pid_t child_pid;
extern int status;
extern char **environ;
extern char *error_ptr;

void display_prompt(void);
char *read_command(void);
void execute_command(const char *command);
void handle_errors(void);
void display_command_not_found_error(void);
void execute_child_process(const char *command);

#endif /* _SHELL_H_ */
