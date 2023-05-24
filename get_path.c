#include "shell.h"

/**
 * check_env_path - get the command path from
 * PATH environment variable
 * @command: enterd command from user
 * Return: NULL when failed else command path
*/
char *check_env_path(char *command)
{
	char *path, *command_path, *token;
	int command_len, path_len, i;

	path = (_getenv("PATH"));
	token = _strtok(path, ":");

	while (token)
	{
		command_len = _strlen(command);
		path_len = _strlen(token);

		command_path = malloc(sizeof(char) * (command_len + path_len + 2));
		if (!command_path)
			return (NULL);

		for (i = 0; token[i]; i++)
			command_path[i] = token[i];

		command_path[path_len++] = '/';

		for (i = 0; command[i]; i++, path_len++)
			command_path[path_len] = command[i];
		command_path[path_len] = '\0';

		if (access(command_path, F_OK) == 0)
		{
			free(path);
			return (command_path);
		}

		free(command_path);
		token = _strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

/**
 * get_path - get the command path
 * @command: enterd command from user
 * Return: comamnd path
*/
char *get_path(char *command)
{
	char *command_path;

	if (command[0] == '/' && access(command, F_OK) == 0)
	{
		command = _strdup(command);
		return (command);
	}

	else if (command[0] == '/' && access(command, F_OK) == -1)
	{
		command = _strdup("null");
		return (command);
	}

	command_path = check_env_path(command);

	if (command_path)
		return (command_path);

	command = _strdup("null");
	return (command);
}
