#include "shell.h"

/**
  * _strlen - function returns the lenght of the str
  * @msg: the str to be counted
  * Return: it returns the length of the string
  */

int _strlen(const char *msg)
{
	int i = 0;

	for (i = 0; msg[i] != '\0'; i++)
		;
	return (i);
}

/**
  * _print - prints the output to standard output
  * @msg: the length of the of the character;
  */

void _print(const char *msg)
{
		write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
  * disp_msg - function display the prompt ($) which display constantly
  *  till terminated
  */

void disp_msg(void)
{
		_print("simple_shell$ ");
}
