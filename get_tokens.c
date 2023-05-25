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
	int i, size = 0, is_quote = 0;

	for (i = 0; argv[i] != '\0'; i++)
	{
		if (is_quote == 0 && argv[i] == '"')
			is_quote = 1;
		else if (is_quote == 1 && argv[i] == '"')
			is_quote = 0;
		if (argv[i] == delim[0] && !is_quote)
			size++;
	}
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
			strip_str = fix_quotes(strip_str);
			words[i] = _strdup(strip_str);
			free(strip_str);
		}
		else
		{
			token = fix_quotes(token);
			words[i] = _strdup(token);
		}
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


/**
 * fix_quotes - remove quotes from echo
 *@str: given str
 *Return: string without double quotes
*/
char *fix_quotes(char *str)
{
	int i, len;

	for (i = 0; str[i]; i++)
	{
		if (str[0] == '"')
		{
			str = &(str[1]);
			len = _strlen(str);
			str[len - 1] = '\0';
		}
	}

	return (str);
}
