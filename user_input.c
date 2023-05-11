#include "shell.h"

/**
 * get_user_input - gets the user input and stores
 *
 * Return: a string that contains the user input to be used else where
 */

ssize_t get_user_input(void)
{
	size_t n;
	char *buffer = NULL;
	ssize_t input;

	printf("> ");
	input = getline(&buffer, &n, stdin);
	
	free(buffer);

	return (input);
}

int main(void)
{
	while(1)
	{
		get_user_input();
	}
	return (0);
}
