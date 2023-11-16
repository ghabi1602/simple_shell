#include "shell.h"

/**
 * find_match - find a character match
 * @s: character to check
 * @str: string to check
 *
 * Return: 1 if match, 0 if not
 */

unsigned int find_match(char s, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (s == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - imitates strtok
 * @str: string
 * @delim: break points in str
 * Return: the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *tok_start;
	static char *next_tok;
	unsigned int i;

	if (str != NULL)
		next_tok = str;
	tok_start = next_tok;
	if (tok_start == NULL)
		return (NULL);
	for (i = 0; next_tok[i] != '\0'; i++)
	{
		if (find_match(next_tok[i], delim) == 0)
			break;
	}
	if (next_tok[i] == '\0' || next_tok[i] == '#')
	{
		next_tok = NULL;
		return (NULL);
	}
	tok_start = next_tok + i;
	next_tok = tok_start;
	for (i = 0; next_tok[i] != '\0'; i++)
	{
		if (find_match(next_tok[i], delim) == 1)
			break;
	}
	if (next_tok[i] == '\0')
		next_tok = NULL;
	else
	{
		next_tok[i] = '\0';
		next_tok = next_tok + i + 1;
		if (*next_tok == '\0')
			next_tok = NULL;
	}
	return (tok_start);
}
