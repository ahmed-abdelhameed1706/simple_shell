#include "shell.h"


/**
 * script_exe - function to read a script file
 * @buffer: user input
 * @re_buf: readed buffer from a file
 * @commands: commands array
 * Return: pointer to pointer array of commands
*/
char **script_exe(char *buffer, char *re_buf, char **commands)
{
	int i, j = 0;
	char tmp_buf[1];
	ssize_t op, re;
	size_t commands_size = 2, buf_size = 2;

	op = open(buffer, O_RDONLY);
	re = read(op, tmp_buf, 1);
	if (op == -1 || re == -1)
	{
		free(re_buf);
		free(commands);
		perror("Error");
		return (NULL);
	}
	for (i = 0; re; i++)
	{
		re_buf[i] = *tmp_buf;
		if (*tmp_buf == '\n')
		{
			re_buf[i + 1] = '\0';
			if (re_buf[0] != '#')
			{
				commands[j] = _strdup(re_buf);
				commands_size++;
				commands = realloc(commands, sizeof(char *) * commands_size);
				j++;
			}
			i = -1;
			buf_size = 2;
			re_buf = realloc(re_buf, sizeof(char) * buf_size);
			re = read(op, tmp_buf, 1);
			continue;
		}
		buf_size++;
		re_buf = realloc(re_buf, sizeof(char) * buf_size);
		re = read(op, tmp_buf, 1);
	}
	commands[j] = NULL;
	free(re_buf);
	return (commands);
}

/**
 * get_commands - get all commands from buffer
 * @buffer: user input
 * @file_name: current file name
 * Return: pointer to pointer array of commands
*/
char **get_commands(char *buffer, char *file_name)
{
	char *re_buf = NULL, **commands = NULL, *rm_new, *error_buf;
	int size;

	re_buf = malloc(sizeof(char) * 2);
	commands = malloc(sizeof(char *) * 2);
	if (!commands || !re_buf)
	{
		free_tokens(commands);
		free(re_buf);
		return (NULL);
	}
	if (buffer[0] != '.')
	{
		free(re_buf);
		if (_strchr(buffer, ';') != NULL)
		{
			free(commands);
			commands = sep_handler(buffer, &size);
			return (commands);
		}
		commands[0] = _strdup(buffer);
		commands[1] = NULL;
		return (commands);
	}
	rm_new = _strchr(buffer, '\n');
	*rm_new = '\0';
	error_buf = _strdup(buffer);
	buffer = &(buffer[2]);
	if (access(buffer, X_OK) != 0)
	{
		handle_permission(error_buf, file_name);
		status_info(126);
		free(error_buf);
		free_tokens(commands);
		free(re_buf);
		return (NULL);
	}

	free(error_buf);
	return (script_exe(buffer, re_buf, commands));
}
