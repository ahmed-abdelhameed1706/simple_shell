#include "shell.h"

/**
 * sig_handler - handle the interrupt signal
 * @sig_num: id of the signal
 * Return: Nothing
*/
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDOUT_FILENO, "\n> ", 3);
}
