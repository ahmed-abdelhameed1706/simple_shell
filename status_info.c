#include "shell.h"

/**
 * status_info - return the current exit status
 *@status: current status
 *Return: current status for last command
*/
int status_info(int status)
{
	static int current_status = 1;

	if (current_status == 1)
		current_status = 0;

	if (status >= 0)
		current_status = status;

	return (current_status);
}
