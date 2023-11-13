#include "shell.h"

/**
 * exec_blt - selects the builtin to execute
 * @exp: array of strings
 * Return: function
 */

int (*exec_blt(char **exp))(char **exp)
{
	blt func_arr[] = {
		{"env", _env},
		/**
		 *{"setenv", _setenv},
		 *{"unsetenv", _unsetenv},
		 *{"exit", _exit},
		 */
		{NULL, NULL}
	};
	int i;
	int num = 2;

	for (i = 0; i < num; i++)
	{
		if (func_arr[i].s == exp[0])
			return (func_arr[i].f);
	}
	return (NULL);
}
