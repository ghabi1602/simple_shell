#include <stdio.h>
#include "shell.h"

/**
  * main - shell starter
  * Return: returns zero on success
  */

int main(void)
{
	char *buffer;
	int pid = getpid();

	while (true)
	{
		disp_msg();
		buffer = reader();
		exec_cmd(buffer, pid);
	}

	free(buffer);
	return (0);
}
