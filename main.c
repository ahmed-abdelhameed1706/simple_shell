#include "shell.h"

/**
 * main - entry point to the program
 *
 * Return: 0 on success
 */
int main(void)
{
	char *buf = NULL, **argv, *deli = " \n";

	while (1)
	{
		buf = get_user_input();
		argv = get_tokens(buf, deli);
		execute(argv);

		free_tokens(argv);
	}
	return (0);
}

