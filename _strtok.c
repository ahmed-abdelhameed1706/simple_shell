#include "shell.h"


/**
 * is_delim - check if the given char is delimiter
 * @str_c: the given char
 * @delim: the given delimiter
 * Return: 1 if match else 0
*/
int is_delim(char str_c, const char *delim)
{
	int i;

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (str_c == delim[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - tokenize a given string by
 * a given delimiter
 * @str: the given string
 * @delim: the given delimiter
 * Return: tokenized string
 * or NULL if it reached the end
*/
char *_strtok(char *str, const char *delim)
{
	static char *backup_str;
	char *token;
	int i, len;

	if (str != NULL)
		backup_str = str;

	if (backup_str == NULL)
		return (NULL);
	len = strlen(backup_str);
	token = backup_str;
	for (i = 0; backup_str[i] != '\0'; i++)
	{
		if (is_delim(backup_str[i], delim))
		{
			if (backup_str[i] == '\n' && len == 1)
				return (NULL);
			backup_str[i] = '\0';
			backup_str = &(backup_str[i + 1]);
			return (token);
		}
	}
	backup_str = NULL;
	return (NULL);
}
