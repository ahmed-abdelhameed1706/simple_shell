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
#include <signal.h>
#include <ctype.h>

/* global variables */

extern char **environ;

/*Prototypes*/
int execute(char **argv);
char *get_user_input();
char **get_tokens(char *argv, char *delim);
void free_tokens(char **tokens);
void get_signal(int sig);
char *get_path(char *command);
int print_env(void);
ssize_t _getline(char **lineptr, size_t *n);
int exit_shell(char *code);

#endif /* SHELL_H */
