#include "shell.h"

/**
 * cd - changes the directory and re-assign the env variables
 * @dir: the directory to be changed to
 *
 * Return: nothing
 */
void cd(char *dir)
{
	char *home, *oldpwd, *cwd;
	int value;

	home = getenv("HOME");
	oldpwd = getenv("OLDPWD");
	cwd = malloc(PATH_MAX);

	if (cwd == NULL)
		return;

	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("cwd");
		free(cwd);
		return;
	}


	if (dir == NULL)
		dir = home;

	else if (_strcmp(dir, "-") == 0)
	{
		dir = oldpwd;
		printf("%s\n", dir);
	}

	value = chdir(dir);
	if (value != 0)
	{
		perror("cd");
	}
	else
	{
		setenv("OLDPWD", cwd, 1);
		setenv("PWD", dir, 1);
	}
	free(cwd);
}
