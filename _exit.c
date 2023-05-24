#include "shell.h"

/**
 * hsh_exit - a fucntion to parse the input exit
 * @argv: the argument to be parsed
 * @buf: the buffer to be freed
 * @file_name: given file name
 * Return: exit code
 */
int hsh_exit(char **argv, char **commands, char *buff, char *file_name)
{
	int exit_arg;

	if (argv[1])
	{
		exit_arg = exit_shell(argv[1], file_name);
		if (exit_arg >= 0)
		{
			free_tokens(argv);
			free_tokens(commands);
			free(buff);
			exit(exit_arg);
		}
	}
	else
	{
		free_tokens(argv);
		free_tokens(commands);
		free(buff);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
