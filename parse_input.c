#include "shell.h"

/**
 * parse_input - parses input coming from user
 * @argv: commands argemunts
 * @commands: list of all commands to free in exit
 * @buff: user input buffer
 * @file_name: given file name
 * Return: 0 on success -1 on failure
 */
int parse_input(char **argv, char **commands, char *buff, char *file_name)
{
	if (!argv[0])
	{
		free_tokens(argv);
		return (0);
	}
	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
		{
			hsh_exit(argv, commands, buff, file_name);
			return (0);
		}
		free_tokens(argv);
		free(buff);
		free_tokens(commands);
		exit(status_info(-1));
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		cd(argv[1]);
		free_tokens(argv);
		return (0);
	}
	return (-1);
}
