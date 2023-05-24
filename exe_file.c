#include "shell.h"

/**
 * exe_file - executes a file if there was any
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success -1 on failure
 */
int exe_file(int argc, char *argv[])
{
	char *command, **commands = NULL;

	if (argc == 2)
	{
		command = argv[1];
		commands = malloc(sizeof(char *) * 2);
		commands[0] = command;
		commands[1] = NULL;
		execute(command, commands);
		free(commands);
		return (0);
	}
	return (-1);
}
