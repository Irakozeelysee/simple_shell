#include "shell.h"
/**
 * custom_strcspn - Custom implementation of strcspn function
 * @str: The input string
 * @reject: The characters to reject
 * Return: The length of the initial segment of str
 * that does not contain any characters from reject.
 */
size_t custom_strcspn(const char *str, const char *reject)
{
	size_t i, j;
	int found;

	for (i = 0; str[i] != '\0'; i++)
	{
		found = 0;
		for (j = 0; reject[j] != '\0'; j++)
		{
			if (str[i] == reject[j])
			{
				found = 1;
				break;
			}
		}
		if (found)
		{
			break;
		}
	}
	return (i);
}

