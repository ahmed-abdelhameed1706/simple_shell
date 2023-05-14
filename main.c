#include "shell.h"

/**
 * main - entry point to the program
 *
 * Return: 0 on success
 */
int main(void)
{
	char *buf = NULL, *command, **argv, *deli = " \n";
	int parse_return_value;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		buf = get_user_input();
		argv = get_tokens(buf, deli);

		parse_return_value = parse_input(argv, buf);
		if (parse_return_value == 0)
			continue;

		command = get_path(argv[0]);
		
		if (strcmp(command, "null") != 0)
		{
			execute(command, argv);
		}
		else
			perror("Error");
			
		free_tokens(argv);
		free(command);
		free(buf);
	}
	return (0);
}

