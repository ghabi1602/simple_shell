#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the new string
 */
char *_strdup(const char *str)
{
	char *dupstr;
	int len = 0, j;

	if (!str)
		return (NULL);

	while (str[len] != '\0')
		len++;

	dupstr = malloc(sizeof(char) * len + 1);

	if (!dupstr)

		return (NULL);

	for (j = 0; j < len; j++)
	{
		dupstr[j] = str[j];
	}

	return (dupstr);
}

/**
 * _strcspn - calculates the length of the initial segment of s
 * which consists entirely of bytes not in reject.
 * @str: the string to check within
 * @reject: the set of characters to reject
 * Return: length of segment
 */
size_t _strcspn(const char *str, const char *reject)
{
	size_t i, j, len;

	if (!str || !reject)
		return (0);

	len = 0;
	while (str[len] != '\0')
		len++;

	if (reject[0] == '\0')
		return (len);

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (str[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
/**
 * _strcmp - compares two strings
 * @s: string
 * @str: string
 * Return: -1 1 or 0(equal)
 */
int _strcmp(const char *s, const char *str)
{
	int len1, len2, i;

	len1 = _strlen(s);
	len2 = _strlen(str);

	if (len1 != len2)
		return (-1);

	for (i = 0; i < len1; i++)
	{
		if (s[i] != str[i])
			return (-1);
	}
	return (1);
}
