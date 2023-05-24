#include "shell.h"

/**
 * get_tokens - breaks a sentence into just array of words
 * @argv: a sentence
 * @delim: spaces between words
 *
 * Return: array of strings
 */
char **get_tokens(char *argv, char *delim)
{
	char *token, **words, *strip_str;
	int i, size = 0;

	for (i = 0; argv[i] != '\0'; i++)
		if (argv[i] == delim[0])
			size++;
	size++;

	words = malloc(sizeof(char *) * (size + 1));
	if (!words)
		return (NULL);

	token = _strtok(argv, delim);

	for (i = 0; token; i++)
	{
		if (token[0] == ' ' || token[_strlen(token) - 1] == ' ')
		{
			strip_str = remove_spaces(token);
			words[i] = _strdup(strip_str);
			free(strip_str);
		}
		else
			words[i] = _strdup(token);
		token = _strtok(NULL, delim);
	}

	words[i] = NULL;
	return (words);
}

/**
 * free_tokens - frees the space of the tokens we already used
 * @tokens: tokens to be freed
 *
 * Return: nothing
 */

void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	free(tokens);
	tokens = NULL;
}
