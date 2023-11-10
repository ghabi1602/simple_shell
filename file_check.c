#include "shell.h"

/**
 * check_for_file - looks for a file in a directory
 * @path: the path to the dir
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
 * rm_arg_0 - function remove the first arg in an array
 * @arr: the array
 * Return: retrun the rest of the array
 */

char *rm_arg_0(char *arr)
{
	int i = 1;
	char *c_arr;

	c_arr = malloc(sizeof(arr));

	if (c_arr == NULL)
	{
		free(c_arr);
		return (NULL);
	}

	while (*arr != '\0')
	{
		c_arr[i] = arr[i];
		i++;
	}

	return (c_arr);
}

/**
 * parse_func - parses a function into tokens
 * @str: the string to be parsed
 * @cmd_arr: where the array will be stored outside the func
 */

void parse_func(const char *str, char *cmd_arr[128])
{
	int i, j;
	char buf[128];
	char *tok;

	for(j = 0; j < 128; j++)
		buf[j] = '\0';

	tok = strtok((char *)str, " ");
	i = 0;
	while (tok != NULL)
	{
		_strcpy(buf, tok);
		cmd_arr[i] = _strdup(buf);
		tok = strtok(NULL, " ");
		i++;
	}
	cmd_arr[i] = NULL;
}
