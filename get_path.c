#include "shell.h"

/**
 * get_path - get the command path
 * @command: enterd command
 * Return: comamnd path
*/
char *get_path(char *command)
{
	char *command_path, *token;
	int command_len, path_len, i;
	char path[] = "/home/vagrant/bin:/home/vagrant/.local/bin:/usr/local/sbin:\
			/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:\
			/usr/games:/usr/local/games:/snap/bin";


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

	token = _strtok(path, ":");
	while (token)
	{
		command_len = strlen(command);
		path_len = strlen(token);
		command_path = malloc(sizeof(char) * (command_len + path_len + 2));
		for (i = 0; token[i]; i++)
			command_path[i] = token[i];

		command_path[path_len++] = '/';

		for (i = 0; command[i]; i++, path_len++)
			command_path[path_len] = command[i];
		command_path[path_len] = '\0';

		if (access(command_path, F_OK) == 0)
			return (command_path);

		free(command_path);
		token = _strtok(NULL, ":");
	}
	command = strdup("null");
	return (command);
}
