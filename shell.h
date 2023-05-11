#ifndef SHELL_H
#define SHELL_H

/* #Includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*Prototypes*/
int execute(char **argv);
char *get_user_input();
char **get_tokens(char *argv, char *delim);
void free_tokens(char **tokens);
#endif /* SHELL_H */
