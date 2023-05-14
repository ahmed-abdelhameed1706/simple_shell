#include "shell.h"

/**
 * main - entry point to the program
 *
 * Return: 0 on success
 */
int main(void)
{
	char *buf = NULL, *command, **argv, *deli = " \n";
	int exit_arg;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		buf = get_user_input();
		argv = get_tokens(buf, deli);
		
	if (!argv[0])
		{
			free_tokens(argv);
			free(buf);
			continue;
		}

		if (strcmp(argv[0], "exit") == 0)
		{
			if (argv[1])
			{
				exit_arg = exit_shell(argv[1]);
				if (exit_arg >= 0)
				{
					free_tokens(argv);
					free(buf);
					exit(exit_arg);
				}
			}
			else
			{
				free_tokens(argv);
				free(buf);
				exit(0);
			}
		}
		else if (strcmp(argv[0], "env") == 0)
			print_env();
		else if (strcmp(argv[0], "cd") == 0)
		{
			cd(argv[1]);
			free_tokens(argv);
			free(buf);
			continue;
		}
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

