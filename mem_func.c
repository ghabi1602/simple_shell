#include "shell.h"

/**
 * _realloc - imitates the realloc 
 * @ptr: ptr to old mem
 * @size: ptr to num of element in old arr
 * Return: pointer to new mem
 */

char **_realloc(char **ptr, size_t *size)
{
	char **newmem;
	size_t i;

	newmem = malloc(sizeof(char *) * ((*size) + 10));
	if (newmem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		newmem[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (newmem);
}
