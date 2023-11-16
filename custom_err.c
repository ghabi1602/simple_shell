#include "shell.h"

/**
 * print_err - print err msg to stderr
 * @vars: pointer to shell_data
 * @msg: error msg
 */
void print_err(sh_data *data, char *msg)
{
	char *err_count;

	_print_err(data->argv[0]);
	_print_err(": ");
	err_count = _utoa(data->num);
	_print_err(err_count);
	free(err_count);
	_print_err(": ");
	_print_err(data->exp[0]);
	if (msg)
	{
		_print_err(msg);
	}
	else
		perror("");
}

/**
 * _print_err - print a string to stderr
 * @str: message
 */
void _print_err(char *str)
{
	ssize_t i, n;

	i = _strlen(str);
	n = write(STDERR_FILENO, str, i);
	if (n != i)
	{
		perror("Fatal Error!");
		exit(1);
	}

}

/**
 * _utoa - convert uint to str
 * @n: the number to be converted 
 * Return: ptr to str
 */
char *_utoa(unsigned int n)
{
	char *str;
	unsigned int temp, num;

	temp = n;
	for (num = 0; temp != 0; num++)
		temp /= 10;
	str = malloc(sizeof(char) * (num + 1));
	if (str == NULL)
	{
		perror("Fatal Error!");
		exit(127);
	}
	str[num] = '\0';
	for (--num; n; --num)
	{
		str[num] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
