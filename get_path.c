#include "shell.h"

/**
 * get_path - get the command path
 * @command: enterd command
 * Return: comamnd path
*/
char *get_path(char *command)
{
	char *bin;
	int len = 0, i;

	if (command[0] == '/' && access(command, F_OK) == 0)
	{
		command = strdup(command);
		return (command);
	}
	else if (command[0] == '/' && access(command, F_OK) == -1)
	{
		command = strdup("null");
		return (command);
	}
	while (command[len])
		len++;

	bin = malloc(sizeof(char) * (len + 6));
	strcpy(bin, "/bin/");

	for (i = 0; i < len; i++)
		bin[i + 5] = command[i];
	bin[i + 5] = '\0';

	if (access(bin, F_OK) == 0)
	{
		command = strdup(bin);
		free(bin);
		return (command);
	}

	free(bin);
	command = strdup("null");
	return (command);
}
