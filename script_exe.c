#include "shell.h"


/**
 * script_exe - function to read a script file
 * @buffer: user input
 * Return: pointer to pointer array of commands
*/
char **script_exe(char *buffer)
{
	ssize_t op, re;
	size_t commands_size = 2, buf_size = 2;
	char *re_buf = NULL, **commands = NULL, tmp_buf[1], *rm_new;
	int i = 0, j = 0;

	re_buf = malloc(sizeof(char) * buf_size);
	commands = malloc(sizeof(char *) * commands_size);
	if (!commands || !re_buf)
	{
		free_tokens(commands);
		free(re_buf);
		return (NULL);
	}

	if (buffer[0] != '.')
	{
		free(re_buf);
		commands[0] = strdup(buffer);
		commands[1] = NULL;
		return (commands);
	}

	buffer = &(buffer[2]);
	rm_new = strchr(buffer, '\n');
	*rm_new = '\0';
	op = open(buffer, O_RDONLY);
	re = read(op, tmp_buf, 1);

	if (op == -1 || re == -1)
	{
		free(re_buf);
		free_tokens(commands);
		perror("Err");
		return (NULL);
	}

	while (re != 0)
	{
		if (*tmp_buf == '\n')
		{
			re_buf[i] = *tmp_buf;
			re_buf[i + 1] = '\0';
			commands[j] = strdup(re_buf);

			i = 0;
			buf_size = 2;
			commands_size++;
			j++;

			commands = realloc(commands, sizeof(char *) * commands_size);
			re_buf = realloc(re_buf, sizeof(char) * buf_size);

			re = read(op, tmp_buf, 1);
			continue;
		}
		re_buf[i] = *tmp_buf;

		buf_size++;

		re_buf = realloc(re_buf, sizeof(char) * buf_size);
		re = read(op, tmp_buf, 1);
		i++;
	}
	commands[j] = NULL;
	free(re_buf);
	return (commands);
}
