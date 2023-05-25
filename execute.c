#include "shell.h"

static int error_count = 1;
/**
 * execute - executes the program from the user input
 * @argv: array of strings to execute
 * @command: command to be executed
 *
 * Return: 0 on success
 */
int execute(char *command, char **argv)
{
	int status;
	char **env = environ;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(command, argv, env) == -1)
			perror("Error:");
	}
	wait(&status);
	if (status == 512)
		status_info(2);
	else if (status == 256)
		status_info(1);
	else
		status_info(status);

	error_count++;
	return (0);
}

/**
 * exit_shell - checks if the argument after the exit
 * function is a positive number
 * @code: the string that should be converted to
 * number under conditions
 * @file_name: given file name
 * Return: the exit code
 */
int exit_shell(char *code, char *file_name)
{
	int exit_code, i;

	if (code == NULL)
		return (0);

	for (i = 0; code[i] != '\0'; i++)
	{
		if (!isdigit(code[i]))
		{
			fprintf(stderr, "%s: %d: Illegal number: %s\n",
					file_name, error_count++, code);
			return (-1);
		}
	}
	exit_code = _atoi(code);

	return (exit_code);
}

/**
 * handle_errors - handles errors like sh
 * @command: name of the command
 * @file_name: file name
 *
 * Return: nothing
 */

void handle_errors(char *command, char *file_name)
{
	fprintf(stderr, "%s: %d: %s: not found\n", file_name, error_count++, command);
}

/**
 * handle_permission - handles permission errors
 * @com: name of the command
 * @file: file name
 *
 * Return: nothing
 */

void handle_permission(char *com, char *file)
{
	fprintf(stderr, "%s: %d: %s: Permission denied\n", file, error_count++, com);
}
