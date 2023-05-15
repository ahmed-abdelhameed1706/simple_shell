#include "shell.h"

/**
 * main - entry point to the program
 *
 * Return: 0 on success
 */
int main(void)
{
	char *buf = NULL, *command, **argv, **commands, *deli = " \n";
	int parse_return_value, i;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		buf = get_user_input();
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

			command = get_path(argv[0]);

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

