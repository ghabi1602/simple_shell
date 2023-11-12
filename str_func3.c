#include "shell.h"

/**
 * find_delim - this checks for delim
 * @str: string holder
 * @delim: the delim
 * Return: returns 1  or 0
 */

int find_delim(char str[], const char *delim)
{
	unsigned int a, b, c;

	for (a = 0, c = 0; str[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (str[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: string to be checked.
 * Return: pointer to string
 */
char *_strtok(char str[], const char *delim)
{
	static char *sep_str, *str_end;
	char *str_start;
	unsigned int i, b;

	if (str != NULL)
	{
		if (find_delim(str, delim))
			return (NULL);
		sep_str = str; /*get first addr*/
		i = _strlen(str);
		str_end = &str[i]; /*get last addr*/
	}
	str_start = sep_str;
	if (str_start == str_end) /*goto end*/
		return (NULL);
	for (b = 0; *sep_str; sep_str++)
	{
		if (sep_str != str_start)
			if (*sep_str && *(sep_str - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*sep_str == delim[i])
			{
				*sep_str = '\0';
				if (sep_str == str_start)
					str_start++;
			}
			break;
		}
		if (b == 0 && *sep_str)
			b = 1;
	}
	if (b == 0)
		return (NULL);
	return (str_start);
}
