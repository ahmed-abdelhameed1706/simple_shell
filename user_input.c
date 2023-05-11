#include "shell.h"

/**
 * get_user_input - gets the user input and stores
 *
 * Return: a string that contains the user input to be used else where
 */

char *get_user_input(void)
{
	size_t n = 0;
	char *buffer = NULL;
	ssize_t val;

	printf("> ");
	val = getline(&buffer, &n, stdin);

	if (val == -1)
	{
		printf("\n");
		free(buffer);
		exit(0);
	}

	return (buffer);
}
