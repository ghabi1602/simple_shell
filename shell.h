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

/* list of declared functions */
void disp_msg(void);
void _print(const char *msg);
int _strlen(const char *msg);
int exec_cmd(char *cmd);
char *reader(void);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
size_t _strcspn(const char *str, const char *reject);
void _printenv(void);
char *_getenv(const char *env);
int _strcmp(const char *s, const char *str);
void parse_func(char *str, char **cmd_arr);
char **rm_arg(char **arr);
char *check_for_file(char **path_arr, char *exe_name);
char **expansion(char **);

#endif /* SHELL_H */
