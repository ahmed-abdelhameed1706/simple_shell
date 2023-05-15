#include "shell.h"

void strip(char **str)
{
	char *tmp_str = str;
	int start_point, end_point, i;

	for (start_point = 0; tmp_str[start_point] == ' ';)
		start_point++;

	tmp_str = &(tmp_str[start_point]);

	end_point = strlen(tmp_str) - 1;

	while (tmp_str[end_point] == ' ')
		end_point--;
	end_point++;

	*str = realloc(*str, sizeof(char) * (end_point + 2));

	for (i = 0; i < end_point; i++, start_point++)
		str[i] = tmp_str[start_point];
}
