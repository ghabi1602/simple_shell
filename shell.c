#include <stdio.h>
#include "shell.h"

/**
  * main - shell starter
  * Return: returns zero on success
  */

int main(void)
{
	char **cpenv, *buffer;
	int pid = getpid();

	cpenv = copy_env();

	while (true)
	{
		disp_msg();
		buffer = reader();
		exec_cmd(buffer, pid, cpenv);
	}

	free(buffer);
	return (0);
}
