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

	home = getenv("HOME");
	oldpwd = getenv("OLDPWD");
	cwd = malloc(PATH_MAX);

	if (cwd == NULL)
		return;
	
	getcwd(cwd, PATH_MAX);

	if (dir == NULL)
		dir = home;
	
	else if (strcmp(dir, "-") == 0)
	{
		dir = oldpwd;
		printf("%s\n", dir);
	}
	if (chdir(dir) != 0)
		perror("cd");
	else
	{
		setenv("OLDPWD", cwd, 1);
		setenv("PWD", dir, 1);
	}
	free(cwd);
}
