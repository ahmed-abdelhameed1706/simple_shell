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
		len = strlen(input_tokens[*size]);
		input_tokens[*size] = realloc(input_tokens[*size], sizeof(char) * (len + 2));
		input_tokens[*size][len] = '\n';
		input_tokens[*size][len + 1] = '\0';
		(*size)++;
	}
	return (input_tokens);
}

/**
 */

char **strip_tokens(char *buf, char *delim, int *size)
{
	char **tokens = NULL, *buf_cp, *start, *end, *token, *last_token;
	size_t last_len;
	*size = 0;

	buf_cp = strdup(buf);

	if (buf_cp == NULL)
		return (NULL);

	token = _strtok(buf_cp, delim);

	while (token != NULL)
	{
		start = token;
		end = token + strlen(token) - 1;

		while (*start && isspace((unsigned char) *start))
			start++;
		while (end > start && isspace((unsigned char) *end))
			end--;
		*(end + 1) = '\0';

		tokens = realloc(tokens, (*size + 1) * sizeof(char *));

		if (tokens == NULL)
		{
			free(buf_cp);
			return (NULL);
		}
		tokens[*size] = strdup(start);
		(*size)++;

		token = _strtok(NULL, delim);
	}
	if (*size > 0)
	{
		last_token = tokens[*size - 1];
		last_len = strlen(last_token);
		if (last_len > 0 && last_token[last_len - 1] == '\n')
			last_token[last_len - 1] = '\0';
	}
	free(buf_cp);
	return (tokens);
}

char *remove_spaces(char *input)
{
	int input_len, i , j , in_space = 0;
	char *striped_token;

	input_len = strlen(input);

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
