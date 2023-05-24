#include "shell.h"

/**
 * _getline - get a line from stdin
 * @lineptr: the buffer to store the line
 * @n: buffer size
 * @stream: the file where input will be taken
 * Return: buffer size
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t read_chars = 0;
	char *line_end = NULL;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	*n = 128;
	*lineptr = malloc(sizeof(char) * (*n));
	if (*lineptr == NULL)
		return (-1);

	while (fgets(*lineptr + read_chars, *n - read_chars, stream) != NULL)
	{
		read_chars += _strlen(*lineptr + read_chars);
		line_end = _strchr(*lineptr, '\n');
		if (line_end != NULL)
			return (read_chars);
		if (*n - read_chars < 128)
		{
			*n += 128;
			*lineptr = realloc(*lineptr, sizeof(char) * (*n));
			if (*lineptr == NULL)
				return (-1);
		}
	}

	return (-1);
}
