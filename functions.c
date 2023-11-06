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
/**
 * _realloc - reallocates a new memory space
 * @ptr: pointer to an allocated memory space
 * @old_size: integer
 * @new_size: integer
 * Return: pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *p1;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		return (malloc(new_size));
	}
	p = malloc(new_size);
	if (!p)
		return (NULL);
	p1 = ptr;
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			p[i] = p1[i];
	}
	if (new_size < old_size)
		for (i = 0; i < new_size; i++)
			p[i] = p1[i];
	free(ptr);
	return (p);
}
