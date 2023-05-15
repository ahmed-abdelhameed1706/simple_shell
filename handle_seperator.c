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
