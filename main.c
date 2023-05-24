#include "shell.h"

/**
 * main - entry point to the program
 * @argc: number of arguments
 * @argvv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argvv[])
{
	char *buf = NULL, *command, **argv, **commands = NULL, *deli = " \n";
	char *delim = ";";
	int parse_return_value, i, exit_status = EXIT_SUCCESS;

	if (exe_file(argc, argvv) == 0)
		return (0);
	while (1)
	{
		buf = get_user_input(exit_status);
		if (_strchr(buf, ';') != NULL)
			commands = strip_tokens(buf, delim);
		else
			commands = get_commands(buf);
		if (!commands)
		{
			free(buf);
			continue;
		}
		for (i = 0; commands[i] != NULL; i++)
		{
			exit_status = EXIT_SUCCESS;
			argv = get_tokens(commands[i], deli);
			parse_return_value = parse_input(argv, commands, buf, argvv[0]);
			if (parse_return_value == 0)
				continue;
			command = get_path(argv[0]);
			if (_strcmp(command, "null") != 0)
				execute(command, argv);
			else
			{
				handle_errors(argv[0], argvv[0]);
				exit_status = EXIT_FAILURE;
			}
			free_tokens(argv);
			free(command);
		}
		free(buf);
		free_tokens(commands);
	}
	return (0);
}
