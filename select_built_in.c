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
		{"cd", select_cd},
		/*{"setenv", _setenv},*/
		/*{"unsetenv", _unsetenv},*/
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

/**
 * select_cd - choose the cd option
 * @exp: array of string after cd
 * Return: return 1 on success
 */

int select_cd(char **exp)
{
	char *dir;
	int home1, home2, home3;

	dir = exp[1];

	if (dir != NULL)
	{
		home1 = _strcmp("$HOME", dir);
		home2 = _strcmp("--", dir);
		home3 = _strcmp("~", dir);
	}
	if (dir == NULL || !home1 || !home2 || !home3)
	{
		cd_home();
		return (1);
	}
	if (_strcmp("-", dir) == 1)
	{
		cd_prev();
		return (1);
	}
	if (_strcmp(".", dir) == 1 || _strcmp("..", dir) == 1)
	{
		cd_back();
		return (1);
	}

	cd_to(exp);

	return (1);
}
