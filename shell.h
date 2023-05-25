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
int execute(char *command, char **argv);
char *get_user_input(void);
char **get_tokens(char *argv, char *delim);
void free_tokens(char **tokens);
void get_signal(int sig);
char *get_path(char *command);
int print_env(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int exit_shell(char *code, char *file_name);
void cd(char *dir);
int hsh_exit(char **argv, char **commands, char *buff, char *file_name);
int parse_input(char **argv, char **commmands, char *buf, char *file_name);
int is_delim(char str_c, const char *delim);
char *_strtok(char *str, const char *delim);
char **script_exe(char *buffer, char *re_buf, char **commands);
char **get_commands(char *buffer, char *file_name);
char **sep_handler(char *buf, int *size);
char *strip(char *str);
char **strip_tokens(char *buf, char *delim);
char *remove_spaces(char *input);
char *_getenv(const char *name);
int count_tokens(char *str, char *delim);
char *check_env_path(char *command);
int exe_file(int argc, char *argv[]);
void handle_errors(char *command, char *file_name);
void sig_handler(int sig_num);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strchr(const char *s, int c);
int _strlen(const char *s);
int _atoi(const char *s);
int status_info(int status);
void handle_permission(char *com, char *file);
char *fix_quotes(char *str);
#endif /* SHELL_H */
