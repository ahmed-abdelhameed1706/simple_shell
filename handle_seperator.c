#include "shell.h"

/**
 * sep_handler - function that tokenize the input if it contains a ;
 * @buf: pointer to the input buffer
 * @size: number of tokens
 *
 * Return: an array of strings to be parsed
 */
char **sep_handler(char *buf, int *size)
{
	char *deli = ";\n", **input_tokens;
	int len;

	input_tokens = get_tokens(buf, deli);

	*size = 0;

	while (input_tokens[*size] != NULL)
	{
		len = _strlen(input_tokens[*size]);
		input_tokens[*size] = realloc(input_tokens[*size], sizeof(char) * (len + 2));
		input_tokens[*size][len] = '\n';
		input_tokens[*size][len + 1] = '\0';
		(*size)++;
	}
	return (input_tokens);
}

/**
 * strip_tokens - strips strings from spaces and tokinize it
 * @buf: string to be tokenized
 * @delim: delimitar
 *
 * Return: array of tokens
 */

char **strip_tokens(char *buf, char *delim)
{
	char **tokens = NULL, *buf_cp, *start, *end, *token, *last_token;
	size_t last_len;
	int i, size = count_tokens(buf, delim);

	buf_cp = _strdup(buf);
	if (buf_cp == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * (size + 1));
	if (tokens == NULL)
	{
		free(buf_cp);
		return (NULL);
	}
	token = _strtok(buf_cp, delim);
	for (i = 0; token; i++)
	{
		start = token;
		end = token + _strlen(token) - 1;
		while (*start && isspace((unsigned char) *start))
			start++;
		while (end > start && isspace((unsigned char) *end))
			end--;
		*(end + 1) = '\0';
		tokens[i] = _strdup(token);
		token = _strtok(NULL, delim);
	}
	if (size > 0)
	{
		last_token = tokens[size - 1];
		last_len = _strlen(last_token);
		if (last_len > 0 && last_token[last_len - 1] == '\n')
			last_token[last_len - 1] = '\0';
	}
	tokens[i] = NULL;
	free(buf_cp);
	return (tokens);
}

/**
 * remove_spaces - removes spaces from input
 * @input: string to remove spaces from
 *
 * Return: striped string
 */

char *remove_spaces(char *input)
{
	int input_len, i, j, in_space = 0;
	char *striped_token;

	input_len = _strlen(input);

	striped_token = malloc((input_len + 1) * sizeof(char));

	if (striped_token == NULL)
		return (NULL);

	for (i = 0, j = 0; i < input_len; i++)
	{
		if (isspace(input[i]))
		{
			if (in_space == 1)
			{
				striped_token[j++] = ' ';
				in_space = 1;
			}
			else
			{
				striped_token[j++] = input[i];
				in_space = 0;
			}
		}
	}
	striped_token[j] = '\0';
	return (striped_token);
}

/**
 * count_tokens - counts number of tokens based on a delim
 * @str: string to count tokens in
 * @delim: a delim
 *
 * Return: number of tokens
 */

int count_tokens(char *str, char *delim)
{
	char *tokens_cp, *token;
	int count = 0;

	tokens_cp = _strdup(str);
	token = _strtok(tokens_cp, delim);

	while (token)
	{
		count++;
		token = _strtok(NULL, delim);
	}
	free(tokens_cp);
	return (count);
}
