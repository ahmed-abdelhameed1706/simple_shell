#include "shell.h"

/**
 * execute - executes the program from the user input
 * @argv: array of strings to execute
 *
 * Return: 0 on success
 */
int execute(char **argv)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error:");
	}
	wait(NULL);
	return (0);
}
