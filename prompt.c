#include "shell.h"

/**
 * display_prompt - Displays the prompt that indicates where to start.
 */

void display_prompt(void)
{
	char prompt[] = "$ ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}
