#include "shell.h"

/**
 * print_env - loops through env and prints it
 *
 * Return: 0 on success
 */
int print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
