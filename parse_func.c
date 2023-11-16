#include "shell.h"


/**
 * parse_func -breaks a buffer with a delimiter
 * @buf: string buffer
 * @delim: beak points
 *
 * Return: pointer to an array of pointers to token
 */
char **parse_func(char *buf, char *delim)
{
	char **tok = NULL;
	size_t i = 0, max_c = 10;

	if (buf == NULL)
		return (NULL);
	tok = malloc(sizeof(char *) * max_c);
	if (tok == NULL)
	{
		perror("Error (Fatal)");
		return (NULL);
	}
	while ((tok[i] = _strtok(buf, delim)) != NULL)
	{
		i++;
		if (i == max_c)
		{
			tok = _realloc(tok, &max_c);
			if (tok == NULL)
			{
				perror("Error (Fatal)");
				return (NULL);
			}
		}
		buf = NULL;
	}
	return (tok);
}
