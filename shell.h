#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>

/*unsigned int flag;*/
/**
 * struct shell_data -  shell variables on start
 * @exp: tokenise command args
 * @buf: command buffer
 * @env: passed environment
 * @num: num of args passed
 * @argv: args vector
 * @status: exit status
 * @ptr_cmd: double pointer to tokenised command
 */

typedef struct shell_data
{
	char **exp;
	char **argv;
	char *buf;
	char **ptr_cmd;
	char **env;
	size_t num;
	int status;
} sh_data;


/**
 * struct built_in - struct ot call built in func
 * @s: placeholder for the func to call
 * @f: function for corresponding builtin
 */
typedef struct built_in
{
	char *s;
	void (*f)(sh_data *);
} exec_blt;


/* function to handle envrionment */
char **env_cpy(char **env);
void free_envr(char **env);

/* strings functions */
ssize_t _print(char *str);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
unsigned int _strlen(char *str);

/* function parser*/
char **parse_func(char *buf, char *delim);
char **_realloc(char **ptr, size_t *size);
char *_strtok(char *str, const char *delim);

/* Path Handler */
void check_file(sh_data *data);
char *path_hnd(char **env);
int exe_path(char *ptr_cmd, sh_data *data);
int exec_pwd_cmd(sh_data *data);
int check_for_fld(char *str);

/* Environment handlers */
void (*select_builtins(sh_data *data))(sh_data *data);
void c_exit(sh_data *data);
void _env(sh_data *data);
void _setenv(sh_data *data);
void _unsetenv(sh_data *data);

/* env manipulators */
void insert_key(sh_data *data);
char **search_key(char **env, char *key);
char *insert_value(char *key, char *value);
int _atoi(char *str);

/* Error Handling */
void print_err(sh_data *data, char *msg);
void _print_err(char *str);
char *_utoa(unsigned int n);


#endif /* SHELL_H */
