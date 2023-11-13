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
		{"cd", cd_prev},
		/**
		 *{"setenv", _setenv},
		 *{"unsetenv", _unsetenv},
		 *{"exit", _exit},
		 */
		{NULL, NULL}
	};
	int i;
	int num = 3;

	for (i = 0; i < num; i++)
	{
		if (func_arr[i].s == exp[0])
			return (func_arr[i].f);
	}
	return (NULL);
}

/**
 * select_cd - choose the cd option
 * @exp: array of string after cd
 */

int (*select_cd(char **exp))()
{
	cd_st func_arr[] = {
		{"..", cd_prev}
	};

	int i, num = 1;

	for (i = 0; i < num; i++)
	{
		if (func_arr[i].s == exp[1])
			return (func_arr[i].f);
	}

	return (0);
}
