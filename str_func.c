#include "shell.h"

/**
 * _print - print to stdout
 * @str: string
 * Return: number of bytes  or -1 on failure
 */
ssize_t _print(char *str)
{
	ssize_t i, len;

	i = _strlen(str);
	len = write(STDOUT_FILENO, str, i);
	if (len != i)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/**
 * _strdup - duplicates a str or buff
 * @str: string to be duplicated
 *
 * Return: a pointer to the new duplicated string
 */
char *_strdup(char *str)
{
	char *dup;

	int len, i;

	if (str == 0)
		return (NULL);

	for (len = 0; str[len]; len++)
		;
	dup = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 on success
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (str1[i] - str2[i]);
}

/**
 * _strcat - concatenates two strings
 * @dest:string to recieve
 * @src: string to be attached
 * Return: pointer to new str
 */

char *_strcat(char *dest, char *src)
{
	char *concat;
	unsigned int len1, len2, catlen, i, j;

	len1 = 0;
	len2 = 0;
	if (dest == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; dest[len1]; len1++)
			;
	}
	if (src == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; src[len2]; len2++)
			;
	}
	catlen = len1 + len2 + 2;
	concat = malloc(catlen * sizeof(char));
	if (concat == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		concat[i] = dest[i];
	concat[i] = '/';
	for (j = 0; j < len2; j++)
		concat[i + 1 + j] = src[j];
	concat[len1 + len2 + 1] = '\0';
	return (concat);
}

/**
 * _strlen - returns the length of a string
 * @str: string
 * Return: length
 */
unsigned int _strlen(char *str)
{
	unsigned int i;

	i = 0;

	for (i = 0; str[i]; i++)
		;
	return (i);
}
