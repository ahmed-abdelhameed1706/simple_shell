#include "shell.h"

/**
 */
void handle_errors(char *command, char *file_name)
{
	static int errors = 1;

	fprintf(stderr, "%s: %d: %s: not found\n", file_name, errors++, command);
}
