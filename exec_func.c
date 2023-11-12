#include "shell.h"

/**
* exec_cmd - execute the command from the user input
* @cmd: list of string entered by thte user
*/
extern char **environ;

char *exec_cmd(const char *cmd)
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
	p_func = exec_blt(exp);
	if (p_func)
	{
		p_func(exp);
		return (0); }
	_strcat(link, cmd_arr[0]);
	if (access(link, F_OK) == -1)
	{
		perror(cmd_arr[0]);
		return (-1);
	}
	c_pid = fork();
	/* handles error if child not created */
	if (c_pid == -1)
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
