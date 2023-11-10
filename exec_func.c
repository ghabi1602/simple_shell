#include "shell.h"

/**
* exec_cmd - execute the command from the user input
* @cmd: list of string entered by thte user
*/
extern char **environ;

void exec_cmd(const char *cmd)
{
	pid_t c_pid = fork(); /* creates a child process */
	int j;
	char *cmd_arr[128];
	char link[30] = "/usr/bin/";

	for(j = 0; j < 128; j++)
		cmd_arr[j] = NULL;


	/* handles error if child not created */
	if (c_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == 0)
	{
		parse_func(cmd, cmd_arr);
		_strcat(link, cmd_arr[0]);
		execve(link, cmd_arr, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

}
