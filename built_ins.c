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
/**
 * _setenv - sets a new environment
 * @exp: array of input strings
 * Return: integer
 */
int _setenv(char **exp)
{
	char *res, *tok;
	int lenenv = 0, lenenv2 = 0, len = 0, i = 0;

	while (exp[len] != NULL)
		len++;
	if (len != 3)
	{
		perror("Failed number of arguments");
		return (-1); }
	while (environ[lenenv] != NULL)
		lenenv++;
	printf("here is the length before :%d\n", lenenv);
	res = _getenv(exp[1]);
	if (!res)
	{
		environ = _realloc(environ, sizeof(char *) * lenenv, sizeof(char *)
				* (lenenv + 1));

		while (environ[lenenv2] != NULL)
			lenenv2++;
		printf("here is the length afrer realloc: %d\n", lenenv2);
		if (!environ)
			return (-1);
		environ[lenenv] = malloc(sizeof(char) * _strlen(exp[2]) + 1);
		if (!environ[len])
			return (-1);
		environ[lenenv] = _strdup(exp[2]);
		environ[lenenv + 1] = NULL;
		return (1); }
	while (environ[i] != NULL)
	{
		tok = strtok(environ[i], "=");
		if (_strcmp(tok, exp[1]) == 1)
		{
			environ[i] = _realloc(environ[i], sizeof(char) * _strlen(environ[i])
			, sizeof(char) * (_strlen(exp[1]) + _strlen(exp[2])) + 2);
			if (!environ[i])
				return (-1);
			environ[i] = _strdup(exp[1]);
			_strcat(environ[i], "=");
			_strcat(environ[i], exp[2]);
			return (1); }
		i++; }
	return (1);
}
/**
 * _unsetenv - deletes an environment
 * @exp: array of input strings
 * Return: int
 */
int _unsetenv(char **exp)
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
	p = _getenv(exp[1]);
	if (!p)
	{
		perror("Failed: variable doesnt exist!");
		return (-1);
	}
	while (environ[i] != NULL)
	{
		tok = strtok(environ[i], "=");
		if (_strcmp(tok, exp[1]) == 1)
		{
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = _realloc(environ[j], sizeof(char)
* _strlen(environ[j]), sizeof(char) * _strlen(environ[j + 1]));

				if (!environ[j])
					return (-1);
				environ[j] = _strdup(environ[j + 1]);
			}
			free(environ[j]);
			return (1);
		}
		i++;
	}
	return (-1);
}
