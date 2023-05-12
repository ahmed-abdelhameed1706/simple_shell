#include "shell.h"

/**
 * exit_shell - checks if the argument after the exit function is a positive number
 * @code: the string that should be converted to number under conditions
 *
 * Return: the exit code
 */
int exit_shell(char *code)
{
	int exit_code, i;

	if (code == NULL)
		return (0);

	for (i = 0; code[i] != '\0'; i++)
	{
		if (!isdigit(code[i]))
		{
			printf("%s is not a valid exit status\n", code);
			return (-1);
		}
	}
	exit_code = atoi(code);

	return (exit_code);
}
