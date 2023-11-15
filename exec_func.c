#include "shell.h"

/**
* exec_cmd - execute the command from the user input
* @cmd: list of string entered by thte user
* @pid: the main's PID
* @cpenv: array of environments
* Return: int
*/

int exec_cmd(char *cmd, int pid, char **cpenv __attribute__((unused)))
{
	pid_t c_pid; /* creates a child process */
	char **cmd_arr, **exp;
	char link[30] = "/usr/bin/";
	int (*p_func)(char **);

	cmd_arr = parse_func(cmd);
	exp = expansion(cmd_arr);
	if (check_exit(exp) == 1)
		__exit(exp[1], pid);
	p_func = exec_blt(exp);
	if (p_func != NULL)
	{
		p_func(exp);
		return (-1);
	}
	_strcat(link, exp[0]);
	if (access(link, F_OK) == -1)
	{
		perror(exp[0]);
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
	free(*exp);
	return (0);
}
