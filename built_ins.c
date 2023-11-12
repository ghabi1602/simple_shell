#include "shell.h"

extern char **environ;
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
	int lenenv = 0, len = 0, i = 0;

	while (exp[len] != NULL)
		len++;
	if (len != 3)
	{
		perror("Failed number of arguments");
		return (-1); }
	while (environ[lenenv] != NULL)
		lenenv++;
	res = _getenv(exp[1]);
	if (!res)
	{
		environ = _realloc(environ, sizeof(char *) * len, sizeof(char *)
				* (len + 1));
		if (!environ)
			return (-1);
		environ[len] = malloc(sizeof(char) * _strlen(exp[2]) + 1);
		if (!environ[len])
			return (-1);
		environ[len] = _strdup(exp[2]);
		environ[len + 1] = NULL;
		return (1); }
	while (environ[i] != NULL)
	{
		tok = strtok(environ[i], '=');
		if (_strcmp(tok, exp[1]) == 1)
		{
			environ[i] = _realloc(environ[i], sizeof(char) * _strlen(environ[i])
			+ 1, sizeof(char) * (_strlen(exp[1]) + _strlen(exp[2])) + 2);
			if (!environ[i])
				return (-1);
			environ[i] = _strdup(exp[1]);
			_strcat(environ[i], '=');
			_strcat(environ[i], exp[2]);
			return (1); }
		i++; }
	return (1);
}
