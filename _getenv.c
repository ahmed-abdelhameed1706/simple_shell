#include "shell.h"


/**
 * _getenv - get an environment variable
 * @name: name of environment variable
 * Return: environment variable value
*/
char *_getenv(const char *name)
{
	char **env = environ, *tmp_name, *result;
	int i, j;

	for (i = 0; env[i]; i++)
	{
		tmp_name = malloc(sizeof(char) * 2);

		if (!tmp_name)
			break;

		for (j = 0; env[i][j] != '='; j++)
		{
			tmp_name[j] = env[i][j];
			tmp_name = realloc(tmp_name, sizeof(char) * (3 + j));
			if (!tmp_name)
				return (NULL);
		}
		tmp_name[j] = '\0';
		if (_strcmp(tmp_name, name) == 0)
		{
			free(tmp_name);
			result = _strdup((j + 1) + env[i]);
			return (result);
		}
		free(tmp_name);
	}
	return (NULL);
}
