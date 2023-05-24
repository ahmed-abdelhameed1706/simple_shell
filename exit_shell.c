#include "shell.h"


static int error_count = 1;

/**
 * exit_shell - checks if the argument after the exit
 * function is a positive number
 * @code: the string that should be converted to
 * number under conditions
 * @file_name: given file name
 * Return: the exit code
 */
int exit_shell(char *code, char *file_name)
{
	int exit_code, i;

	if (code == NULL)
		return (0);

	for (i = 0; code[i] != '\0'; i++)
	{
		if (!isdigit(code[i]))
		{
			printf("%s: %d: Illegal number: %s\n", file_name, error_count++, code);
			return (-1);
		}
	}
	exit_code = atoi(code);

	return (exit_code);
}

/**
 * handle_errors - handles errors like sh
 * @command: name of the command
 * @file_name: file name
 *
 * Return: nothing
 */

void handle_errors(char *command, char *file_name)
{
	fprintf(stderr, "%s: %d: %s: not found\n", file_name, error_count++, command);
}


