#include "shell.h"

/**
 * get_user_input - gets the user input and stores
 * Return: a string that contains the user input to be used else where
 */

char *get_user_input(void)
{
	size_t n = 0;
	char *buffer = NULL;
	ssize_t val;
	int i;

	if (isatty(STDIN_FILENO))
	{
		signal(SIGINT, sig_handler);
		write(STDOUT_FILENO, "> ", 2);
	}
	val = _getline(&buffer, &n, stdin);

	if (val == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		exit(status_info(-1));
	}
	for (i = 0; buffer[i]; i++)
		if (buffer[i] == '#')
		{
			buffer[i] = '\n';
			buffer[i + 1] = '\0';
			break;
		}

	return (buffer);
}
