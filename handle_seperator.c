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
	char *deli = ";", **input_tokens;

	input_tokens = get_tokens(buf, deli);

	*size = 0;

	while (input_tokens[*size] != NULL)
		(*size)++;

	return (input_tokens);
}
