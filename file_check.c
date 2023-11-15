#include "shell.h"

/**
 * check_for_file - looks for a file in a directory
 * @path_arr: the path to the dir
 * @exe_name: the first element of input
 * Return: returns path to the file and NULL on error
 */
char *check_for_file(char *path_arr[], char *exe_name)
{
	int i, status;
	char *c_path;

	/* error handling incase args are null or empty*/
	if (path_arr == NULL || exe_name == NULL)
		return (NULL);

	i = 0;
	/* iterating through the path_arr */
	while (path_arr != NULL)
	{
		c_path = path_arr[i];
		_strcat(c_path, exe_name);

		if (c_path != NULL)
			return (NULL);

		/* checks if path exist */
		if (access(c_path, F_OK) != -1)
		{
			status = 1;
			break;
		}
		i++;
		c_path = NULL;
	}

	if (!status)
		return (NULL);

	return (path_arr[i]);
}

/**
 * rm_arg - function remove the first arg in an array
 * @arr: the array
 * Return: retrun the rest of the array
 */

char **rm_arg(char **arr)
{
	int i, len = 0;

	while (arr[len] != NULL)
		len++;

	for (i = 0; i < len - 1; i++)
	{
		arr[i] = NULL;
		arr[i] = malloc(sizeof(char) * _strlen(arr[i + 1]) + 1);
		arr[i] = _strdup(arr[i + 1]);
	}
	arr[i] = NULL;
	free(arr);
	return (arr);
}

/**
 * parse_func - parses a function into tokens
 * @str: the string to be parsed
 * @cmd_arr: where the array will be stored outside the func
 */

void parse_func(const char *str, char **cmd_arr)
{
	int i, j;
	char *tok;
	char buff[128];


	tok = _strtok((char *)str, " ");

	i = 0;
	while (tok != NULL)
	{
		_strcpy(buff, tok);
		cmd_arr[i] = _strdup(buff);
		tok = _strtok(NULL, " ");
		i++;
		for (j = 0; j < 128; j++)
			buff[j] = '\0';
	}
	cmd_arr[i] = NULL;
}
