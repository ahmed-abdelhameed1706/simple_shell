#include "shell.h"

int execute(char **argv)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (pid == 0)
	{
		if(execve(argv[0], argv, NULL) == -1)
			perror("Error:");
	}
	wait(NULL);
	return (0);
}
