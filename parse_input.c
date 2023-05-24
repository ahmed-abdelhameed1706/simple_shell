#include "shell.h"

/**
 * parse_input - parses input coming from user
 * @argv: the input
 * @buf: buffer to be freed
 * @file_name: given file name
 * Return: 0 on success -1 on failure
 */
int parse_input(char **argv, char *buf, char *file_name)
{
	if (!argv[0])
	{
		free_tokens(argv);
		return (0);
	}
	if (_strcmp(argv[0], "exit") == 0)
	{
		hsh_exit(argv, buf, file_name);
		return (0);
	}
	else if (_strcmp(argv[0], "env") == 0)
		print_env();
	else if (_strcmp(argv[0], "cd") == 0)
	{
		cd(argv[1]);
		free_tokens(argv);
		return (0);
	}
	return (-1);
}
