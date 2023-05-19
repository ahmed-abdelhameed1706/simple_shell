#include "shell.h"


/**
 * _getenv - get an environment variable
 * @name: name of environment variable
 * Return: environment variable value
*/
char *_getenv(const char *name)
{
	char **env = environ, *tmp;
	char *token;

	while (*env)
	{
		tmp = strdup(*env);
		token = _strtok(*env, "=");
		if (strcmp(token, name) == 0)
		{
			token = _strtok(NULL, "=");
			free(tmp);
			return (token);
		}
		free(tmp);
		env++;
	}
	return (NULL);
}
