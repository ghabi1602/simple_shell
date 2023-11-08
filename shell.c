#include <stdio.h>
#include "shell.h"

/**
  * main - shell starter
  * Return: returns zero on success
  */

int main(void)
{
	char *buffer;

	while (true)
	{
		disp_msg();
		buffer = reader();
		if (_strcmp(buffer, "exit") == 1)
			break;
		exec_cmd(buffer);
	}

	free(buffer);
	return (0);
}
