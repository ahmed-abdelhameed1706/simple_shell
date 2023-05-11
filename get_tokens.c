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
	char **words, *token;
	int i = 0, argc = 0;


	token = strdup(argv);
	token = strtok(token, delim);

	while (token)
	{
		argc++;
		token = strtok(NULL, delim);
	}

	words = malloc(sizeof(char *) * argc);

	if (words == NULL)
		return (NULL);

	argv = strtok(argv, delim);

	while (argv)
	{
		words[i] = strdup(argv);
		i++;
		argv = strtok(NULL, delim);
	}
	
	words[i] = NULL;
	free(token);
	return (words);
}

/**
 * free_tokens - frees the space of the tokens we already used
 * @tokens: tokens to be freed
 *
 * Retunr: nothing
 */

void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
