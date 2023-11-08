#include "shell.h"

/**
* exec_cmd - execute the command from the user input
* @cmd: list of string entered by thte user
*/

void exec_cmd(const char *cmd)
{
	pid_t c_pid = fork(); /* creates a child process */
	char buf[128];
	char *tok;
	char *cmd_arr[128];
	int i = 0;
	char link[30] = "/usr/bin/";

	/* handles error if child not created */
	if (c_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == 0)
	{
		/* parsing the function */
		tok = strtok((char *)cmd, " ");
		while (tok != NULL)
		{
			_strcpy(buf, tok);
			cmd_arr[i] = _strdup(buf);
			tok = strtok(NULL, " ");
			i++;
		}
		cmd_arr[i] = NULL;

		_strcat(link, cmd_arr[0]);

		execve(link, cmd_arr, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

}
