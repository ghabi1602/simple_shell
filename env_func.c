#include "shell.h"

/**
 * _printenv - prints the environments
 * Return: void
 */
extern char **environ;

void _printenv()
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_print(environ[i]);
		_print("\n");
	}
}

/**
 * _getenv - gets an environment variable
 * @env: the environment variable to search for
 * Return: pointer to the corresponding value string.
 */
char *_getenv(const char *env)
{
	char *str_env, *s;
	int i, j, c, len, pos;

	if (env[0] == '\0')
		return (NULL);

	i = 0;
	while (environ[i] != NULL)
	{
		pos = _strcspn(environ[i], "=");
		s = malloc(sizeof(char) * (pos + 1));
		if (s == NULL)
			return (NULL);

		for (j = 0; j < pos; j++)
			s[j] = environ[i][j];
		if (_strcmp(s, env) == 1)
		{
			len = _strlen(environ[i]) - pos;
			str_env = malloc(sizeof(char) * len);
			if (str_env == NULL)
			{
				free(s);
				return (NULL);
			}

			c = 0;
			for (j = pos + 2; environ[i][j] != '\0'; j++, c++)
			{
				str_env[c] = environ[i][j];
			}
			free(s);
			return (str_env);
		}
		i++;
	}
	free(s);
	return (NULL);
}
