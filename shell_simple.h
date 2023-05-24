#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>



#define MAX_ARGUMENTS 10
extern char **Environ; 

/* >>>> built-in.c <<<< */
void _print_environment_variables(void);
void _handle_exit(char **args, char *input);
void _setenv_command(char **args);
void _unsetenv_command(char **args);
void _cd_command(char **args);

/* >>>> functions.c <<<< */
void _remove_newline_char(char *s);
char **_handle_Command_line_arguments(char *input);
pid_t _execute_command(char **args, char **env);
void _check_PATH(char **args, char *env[]);
void _execute_PATH(char **args, char **env);

/* >>>> support_functions.c <<<< */
int _strcmp(char *s1, char *s2);
size_t _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _strconcat(char *dest, char *src);
int _atoi(char *s);


/* >>>> shell.c <<<< */
int shell(void);
void _free_args(char **args);


int _putchar(char c);

#endif
