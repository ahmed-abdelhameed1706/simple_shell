#include "shell.h"

/**
 * main - entry point to the program
 *
 * Return: 0 on success
 */
int main(void)
{
	char *buf = NULL, *command, **argv, **commands, *deli = " \n", *delim = ";";
	int parse_return_value, i, size = 0;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		buf = get_user_input();
		for (i = 0; buf[i]; i++)
			if (buf[i] == '#')
			{
				buf[i] = '\n';
				buf[i + 1] = '\0';
				break;
			}
		if (strchr(buf, ';') != NULL)
			commands = strip_tokens(buf, delim, &size);
		else
			commands = get_commands(buf);
		
		if (!commands)
		{
			free(buf);
			continue;
		}
		for (i = 0; commands[i]; i++)
		{
			argv = get_tokens(commands[i], deli);

			parse_return_value = parse_input(argv, commands[i]);
			if (parse_return_value == 0)
				continue;

			command = get_path(argv[0], _getenv("PATH"));

			if (strcmp(command, "null") != 0)
				execute(command, argv);
			else
				perror("Error");

			free_tokens(argv);
			free(command);
		}
		free(buf);
		free_tokens(commands);
	}
	return (0);
}

