#include "shell.h"

/**
 * _memset - fills memory with a constant type
 * @s: string
 * @b: char
 * @n: integer
 * Return: pointer to a string
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	while (n > 0)
	{
		s[i] = b;
		n--;
		i++;
	}
	return (s);
}

/**
 * _memcpy - copies memory area
 * @dest: string
 * @src: string
 * @n: unsigned integer
 * Return: pointer to dest string
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i = 0;

	while (n > 0)
	{
		dest[i] = src[i];
		n--;
		i++;
	}
	return (dest);
}
