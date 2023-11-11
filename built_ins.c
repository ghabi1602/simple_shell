#include "shell.h"

/**
 * _env - prints environments
 * @exp: array of input strings
 * Return: integer
 */
int _env(__attribute__((unused)) char **exp)
{
	_printenv();
	return (1);
}

