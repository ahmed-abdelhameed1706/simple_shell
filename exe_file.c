#include "shell.h"

/**
 */
int exe_file(int argc, char* argv[])
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
