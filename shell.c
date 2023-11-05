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
		exec_cmd(buffer);
	}		

	return (0);
}
