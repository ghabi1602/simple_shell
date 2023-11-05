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
void exec_cmd(const char *cmd);
char *reader(void);

#endif /* SHELL_H */
