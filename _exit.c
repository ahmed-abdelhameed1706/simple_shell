#include "shell.h"

/**
 * hsh_exit - a fucntion to parse the input exit
 * @argv: the argument to be parsed
 * @buf: the buffer to be freed
 *
 * Return : exit code
 */
int hsh_exit(char **argv, char *buf)
{
	int exit_arg;

	if (argv[1])
	{
		exit_arg = exit_shell(argv[1]);
		if (exit_arg >= 0)
		{
			free_tokens(argv);
			free(buf);
			exit(exit_arg);
		}
	}
	else
	{
		free_tokens(argv);
		free(buf);
		exit(0);
	}
	return (0);
}
