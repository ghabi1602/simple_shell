#include "shell.h"

/**
* exec_cmd - execute the command from the user input
* @cmd: list of string entered by thte user
*/

int exec_cmd(char *cmd)
{
	pid_t c_pid; /* creates a child process */
	int j;
	char *cmd_arr[128], **exp;
	char link[30] = "/usr/bin/";
	int (*p_func)(char **);

	for (j = 0; j < 128; j++)
		cmd_arr[j] = NULL;

	parse_func(cmd, cmd_arr);
	exp = expansion(cmd_arr);
	p_func = exec_blt(cmd_arr);
	if (p_func)
	{
		p_func(exp);
		return (0);
	}
	_strcat(link, cmd_arr[0]);
	if (access(link, F_OK) == -1)
	{
		perror(cmd_arr[0]);
		return (-1);
	}
	c_pid = fork();
	if (c_pid == -1) /* handles if child not created */
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == 0)
	{
		execve(link, exp, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

/**
 * free_mem - free memory from malloc
 * @buf: the buffer to ber released
 */
/**
void free_mem(char *buf[])
{
	int len;

	for(len = 0; buf[len] != '\0'; len++)
		;
	for(; buf[len] != '\0'; len--)
	{
		free(buf[len]);
	}
} */
