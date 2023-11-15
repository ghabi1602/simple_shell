#include "shell.h"

/**
 * _printenv - prints the environments
 * Return: void
 */

int _env(__attribute__((unused)) char **exp, char **cpenv)
{
	int i;

	for (i = 0; cpenv[i] != NULL; i++)
	{
		_print(cpenv[i]);
		_print("\n");
	}
	return (1);
}

/**
 * _getenv - gets an environment variable
 * @env: the environment variable to search for
 * Return: pointer to the corresponding value string.
 */
char *_getenv(const char *env, char **cpenv)
{
	char *str_env, *s;
	int i, j, c, len, pos;

	if (env[0] == '\0')
		return (NULL);

	i = 0;
	while (cpenv[i] != NULL)
	{
		pos = _strcspn(cpenv[i], "=");
		s = strtok(cpenv[i], "=");
		if (_strcmp(s, env) == 1)
		{
			len = _strlen(cpenv[i]) - pos;
			str_env = malloc(sizeof(char) * len);
			if (str_env == NULL)
			{
				free(s);
				return (NULL);
			}

			c = 0;
			for (j = pos + 2; cpenv[i][j] != '\0'; j++, c++)
			{
				str_env[c] = cpenv[i][j];
			}
			free(s);
			return (str_env);
		}
		i++;
	}
	free(s);
	return (NULL);
}
/**
 * expansion - handles the variable expansion
 * @cmd_arr: array of strings
 * Return: array of strings
 */
char **expansion(char **cmd_arr, char **cpenv)
{
	char **exp, *str, buff[30];
	int len = 0, i, c, j;

	while (cmd_arr[len] != NULL)
	{
		len++;
	}
	exp = malloc(sizeof(char *) * (len + 1));
	if (!exp)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		exp[i] = malloc(sizeof(char) * _strlen(cmd_arr[i]) + 1);
		if (!exp[i])
			return (NULL);
		if (cmd_arr[i][0] == '$')
		{
			c = 0;
			for (j = 1; cmd_arr[i][j] != '\0'; j++, c++)
				buff[c] = cmd_arr[i][j];
			buff[c] = '\0';
			str = _getenv(buff, cpenv);
			if (str)
			{
				exp[i] = _realloc(exp[i], sizeof(char) * _strlen(cmd_arr[i]) +
				1, sizeof(char) * _strlen(str) + 1);

				if (!exp[i])
					return (NULL);
				exp[i] = _strdup(str);
			}
			else
			{
				exp[i] = _strdup(cmd_arr[i]);
			}
		}
		else
		{
			exp[i] = _strdup(cmd_arr[i]);
		}
	}
	exp[i] = NULL;
	return (exp);
}
/**
 * copy_env - copies environ
 * @cpenv: array of strings
 * Return: void
 */
char **copy_env()
{
	int len, i;
	char **s;

	len = 0;
	while (environ[len] != NULL)
		len++;

	s = malloc(sizeof(char *) * (len + 1));
	if (!s)
		return (NULL);

	i = 0;
	while (environ[i] != NULL)
	{
		s[i] = malloc(sizeof(char) * _strlen(environ[i]) + 1);
		if (!s[i])
			return (NULL);
		s[i] = _strdup(environ[i]);
		i++;
	}
	return (s);
}
