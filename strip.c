#include "shell.h"

char *strip(char *str)
{
	int start_point, end_point, i;
	char *strip_str;

	for (start_point = 0; str[start_point] == ' ';)
		start_point++;

	end_point = strlen(str) - 1;

	while (str[end_point] == ' ')
		end_point--;
	end_point++;

	strip_str = malloc(sizeof(char) * end_point);

	for (i = 0;start_point < end_point; start_point++, i++)
		strip_str[i] = str[start_point];

	return (strip_str);
}
