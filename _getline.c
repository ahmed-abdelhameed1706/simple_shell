#include "shell.h"

/**
 * _getline - get a line from stdin
 * @lineptr: the buffer to store the line
 * @n: buffer size
 * Return: buffer size
*/
ssize_t _getline(char **lineptr, size_t *n)
{
	int count = 1, i = 0;
	char c, *str;

	str = malloc(sizeof(char));

	while ((c = getchar()) != '\n')
	{
		count++;
		str = realloc(str, sizeof(char) * count);
		str[i] = c;
		i++;
	}
	str[i] = '\n';

	*n = count;
	*lineptr = strdup(str);
	free(str);

	return (count);
}
