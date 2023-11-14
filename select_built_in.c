#include "shell.h"

/**
 * exec_blt - selects the builtin to execute
 * @exp: array of strings
 * Return: function
 */

int (*exec_blt(char **exp))(char **exp, char **cpenv)
{
	blt func_arr[] = {
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};
	int i;

	for (i = 0; func_arr[i].s != NULL; i++)
	{
		if (_strcmp(exp[0], func_arr[i].s) == 1)
			return (func_arr[i].f);
	}
	return (NULL);
}
