#include "shell.h"

/**
 * co_line - alloc mem for _getline
 * @ptr: buffer that takes user input
 * @buf: string being called
 * @k: size of string_line
 * @l: size of buf
 */
void co_line(char **ptr, size_t *k, char *buf, size_t l)
{
	if (*ptr == NULL)
	{
		if  (l > BUFSIZE)
			*k = l;
		else
			*k = BUFSIZE;
		*ptr = buf;
	}
	else if (*k < l)
	{
		if (l > BUFSIZE)
			*k = l;
		else
			*k = BUFSIZE;
		*ptr = buf;
	}
	else
	{
		_strcpy(*ptr, buf);
		free(buf);
	}
}

/**
  * _getline - reads inpt from stdin
  * @ptr: buffer that record input
  * @k: size of buf
  * @strm: stdin to read from
  * Return: The size of bytes
  */

ssize_t _getline(char **ptr, size_t *k, FILE *strm)
{
	int i;
	static ssize_t inpt;
	ssize_t retv;
	char *buf;
	char c = 'z';

	if (inpt == 0)
		fflush(strm);
	else
		return (-1);
	inpt = 0;
	buf = malloc(sizeof(char) * BUFSIZE);
	if (buf == 0)
		return (-1);
	while (c != '\n')
	{
		i = read(STDIN_FILENO, &c, 1);
		if (i == -1 || (i == 0 && inpt == 0))
		{
			free(buf);
			return (-1);
		}
		if (i == 0 && inpt != 0)
		{
			break;
		}
		if (inpt >= BUFSIZE)
			buf = _realloc(buf, inpt, inpt + 1);
		buf[inpt] = c;
		inpt++;
		}
	buf[inpt] = '\0';
	co_line(ptr, k, buf, inpt);
	retv = inpt;
	if (i != 0)
		inpt = 0;
	
	return (retv);
}
