#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* Function prototypes */
void display_prompt(void);
void end_of_file(void);
void execute_command(char *command);
size_t custom_strcspn(const char *str, const char *reject);

#endif /* SHELL_H */
