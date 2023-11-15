#include "shell.h"

/**
 * _setenv - sets a new environment
 * @exp: array of input strings
 * @cpenv: array of environments
 * Return: integer
 */
int _setenv(char **exp, char **cpenv)
{
	char *res, *tok;
	int lenenv = 0, len = 0, i = 0;

	while (exp[len] != NULL)
		len++;
	if (len != 3)
	{
		perror("Failed number of arguments");
		return (-1); }
	while (cpenv[lenenv] != NULL)
		lenenv++;
	res = _getenv(exp[1], cpenv);
	if (!res)
	{
		cpenv = _realloc(cpenv, sizeof(char *) * lenenv, sizeof(char *)
				* (lenenv + 1));
		if (!cpenv)
			return (-1);
		cpenv[lenenv] = malloc(sizeof(char) * _strlen(exp[2]) + 1);
		if (!cpenv[len])
			return (-1);
		_strcpy(cpenv[lenenv], exp[2]);
		cpenv[lenenv + 1] = NULL;
		return (1); }
	while (cpenv[i] != NULL)
	{
		tok = strtok(cpenv[i], "=");
		if (_strcmp(tok, exp[1]) == 1)
		{
			cpenv[i] = _realloc(cpenv[i], sizeof(char) * _strlen(cpenv[i]) + 1
			, sizeof(char) * (_strlen(exp[1]) + _strlen(exp[2])) + 2);
			if (!cpenv[i])
				return (-1);
			_strcpy(cpenv[i], exp[1]);
			_strcat(cpenv[i], "=");
			_strcat(cpenv[i], exp[2]);
			return (1); }
		i++; }
	return (1);
}
/**
 * _unsetenv - deletes an environment
 * @exp: array of input strings
 * @cpenv: array of strings
 * Return: int
 */
int _unsetenv(char **exp, char **cpenv)
{
	int len = 0, i = 0, j;
	char *p, *tok;

	while (exp[len] != NULL)
		len++;
	if (len != 2)
	{
		perror("Failed: number of arguments");
		return (-1);
	}
	p = _getenv(exp[1], cpenv);
	if (!p)
	{
		perror("Failed: variable doesnt exist!");
		return (-1);
	}
	while (cpenv[i] != NULL)
	{
		tok = strtok(cpenv[i], "=");
		if (_strcmp(tok, exp[1]) == 1)
		{
			for (j = i; cpenv[j] != NULL; j++)
			{
				free(cpenv[j]);
				cpenv[j] = _strdup(cpenv[j + 1]);
			}

			return (1);
		}
		i++;
	}
	return (-1);
}
/**
 * check_exit - exit the program
 * @exp: array of input strings
 * Return: int
 */
int check_exit(char **exp)
{
	int i, len;

	len = 0;
	while (exp[len] != NULL)
		len++;

	if (len > 2)
	{
		return (-1);
	}
	if (_strcmp(exp[0], "exit") != 1)
	{
		return (-1);
	}
	if (len == 2)
	{
		for (i = 0; exp[1][i] != '\0'; i++)
			if (exp[1][i] < '0' || exp[1][i] > '9')
				return (-1);
	}
	return (1);
}
/**
 * __exit - exits the shell
 * @s: the status
 * @x: the main PID
 * Return: void
 */
void __exit(char *s, char *x)
{
	int a = _atoi(x);

	if (s)
	{
		_print(s);
		_print("\n");
	}

	exit(a);
}
