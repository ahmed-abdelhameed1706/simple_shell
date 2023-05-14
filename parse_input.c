#include "shell.h"

/**
 */
int parse_input(char **argv, char *buf)
{
	if (!argv[0])
	{
		free_tokens(argv);
		free(buf);
		return (0);
	}
	if (strcmp(argv[0], "exit") == 0)
	{
		hsh_exit(argv, buf);
		return (0);
	}
	else if (strcmp(argv[0], "env") == 0)
		print_env();
	else if (strcmp(argv[0], "cd") == 0)
	{
		cd(argv[1]);
		free_tokens(argv);
		free(buf);
		return (0);
	}
	return (-1);
}
