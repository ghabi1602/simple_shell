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
#include <limits.h>
#include <errno.h>
/*global variables*/
#define BUFSIZE 1024
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

/**
 * struct cd_struct - point to a function
 * @s: name of func to point to
 * @f: func pointer
 * Description: this hlep the cd to handle func
 */

typedef struct cd_struct
{
	char *s;
	int (*f)(char **exp);
} cd_st;

/* list of declared functions */
void disp_msg(void);
void _print(const char *msg);
int _strlen(const char *msg);
int exec_cmd(char *cmd);
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
void parse_func(const char *str, char **cmd_arr);
char **rm_arg(char **arr);
char *check_for_file(char **path_arr, char *exe_name);
char **expansion(char **);
int (*exec_blt(char **))(char **);
int _env(char **);
void free_mem(char *buf[]);
int _setenv(char **exp);
int _unsetenv(char **exp);

/* list of cd functions */
void _pwd(void);
int cd_to(char *cmd_arr[]);
int cd_prev(void);
int select_cd(char **exp);
int cd_back(void);
int cd_home(void);
char *rm_cwd(char *str);

/*getline function declaration */
void co_line(char **ptr, size_t *k, char *buf, size_t l);
ssize_t _getline(char **ptr, size_t *k, FILE *strm);
#endif /* SHELL_H */
