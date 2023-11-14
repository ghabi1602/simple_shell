#ifndef SHELL_H
#define SHELL_H

/* list of called libraries */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;
/**
 * struct builtin - funtion pointer variables
 * @s: name of the func to point
 * @f: function pointer
 *
 * Description: this help with the function that point to builtins
 */

typedef struct builtin
{
	char *s;
	int (*f)(char **exp);
} blt;

/* list of declared functions */
void disp_msg(void);
void _print(const char *msg);
int _strlen(const char *msg);
int exec_cmd(char *cmd, int);
char *reader(void);

/* string function declarations */
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
size_t _strcspn(const char *str, const char *reject);
int find_delim(char str[], const char *delim);
char *_strtok(char str[], const char *delim);

/* builtins and manipulation */
void _printenv(void);
char *_getenv(const char *env);
int _strcmp(const char *s, const char *str);
char **parse_func(const char *str);
char **rm_arg(char **arr);
char *check_for_file(char **path_arr, char *exe_name);
char **expansion(char **);
int (*exec_blt(char **))(char **);
int _env(char **);
int _setenv(char **exp);
int _unsetenv(char **exp);
void __exit(char *, int);
int check_exit(char **);

#endif /* SHELL_H */
