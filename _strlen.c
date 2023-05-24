#include "shell.h"


/**
 * _strlen - gets the string length
 *@s: given string
 *Return: length of string
*/
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
