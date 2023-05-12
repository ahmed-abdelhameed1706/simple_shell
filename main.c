#include "shell.h"

/**
 * main - entry point to the program
 *
 * Return: 0 on success
 */
int main(void)
{
	char *buf = NULL, **argv, *deli = " \n";

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		buf = get_user_input();
		argv = get_tokens(buf, deli);

		if (strcmp(argv[0], "exit") == 0)
		{
			free_tokens(argv);
			free(buf);
			exit(0);
		}

		else if (strcmp(argv[0], "env") == 0)
			print_env();

		argv[0] = get_path(argv[0]);

		if (argv[0])
		{
			execute(argv);
		}
		free_tokens(argv);
		free(buf);
	}
	return (0);
}

