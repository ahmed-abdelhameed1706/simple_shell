#include "shell.h"

/**
 * get_path - get the command path
 * @command: enterd command
 * Return: comamnd path
*/
char *get_path(char *command)
{
	char *usr, *bin;
	int len = 0, i;

	if (command[0] == '/' && access(command, F_OK) == 0)
		return (command);
	else if (command[0] == '/' && access(command, F_OK) == -1)
		return (NULL);

	while (command[len])
		len++;

	usr = malloc(sizeof(char) * (len + 10));
	strcpy(usr, "/usr/bin/");
	bin = malloc(sizeof(char) * (len + 6));
	strcpy(bin, "/bin/");

	for (i = 0; i < len; i++)
		bin[i + 5] = command[i];
	bin[i + 5] = '\0';

	if (access(bin, F_OK) == 0)
	{
		free(usr);
		command = strdup(bin);
		free(bin);
		return (command);
	}
	free(bin);
	for (i = 0; i < len; i++)
		usr[i + 9] = command[i];
	usr[i + 9] = '\0';

	if (access(usr, F_OK) == 0)
	{
		command = strdup(usr);
		free(usr);
		return (command);
	}
	free(usr);
	return (NULL);
}
