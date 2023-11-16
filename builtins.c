#include "shell.h"

/**
 * insert_key - create a new environment variable
 * @data: pointer to shell data
 */
void insert_key(sh_data *data)
{
	unsigned int i;
	char **env_cpy;

	for (i = 0; data->env[i] != NULL; i++)
		;
	env_cpy = malloc(sizeof(char *) * (i + 2));
	if (env_cpy == NULL)
	{
		print_err(data, NULL);
		data->status = 127;
		c_exit(data);
	}
	for (i = 0; data->env[i] != NULL; i++)
		env_cpy[i] = data->env[i];
	env_cpy[i] = insert_value(data->exp[1], data->exp[2]);
	if (env_cpy[i] == NULL)
	{
		print_err(data, NULL);
		free(data->buf);
		free(data->ptr_cmd);
		free(data->exp);
		free_envr(data->env);
		free(env_cpy);
		exit(127);
	}
	env_cpy[i + 1] = NULL;
	free(data->env);
	data->env = env_cpy;
}

/**
 * search_key -search env parameters
 * @env: environment parameters
 * @key: environment var
 *
 * Return: pointer to address of env
 */
char **search_key(char **env, char *key)
{
	unsigned int i, j, len;

	len = _strlen(key);
	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
			if (key[j] != env[i][j])
				break;
		if (j == len && env[i][j] == '=')
			return (&env[i]);
	}
	return (NULL);
}

/**
 * insert_value - insert a var into the env
 * @key: name
 * @value: value
 * Return: pointer to the new string;
 */
char *insert_value(char *key, char *value)
{
	unsigned int len1, len2, i, j;
	char *rep;

	len1 = _strlen(key);
	len2 = _strlen(value);
	rep = malloc(sizeof(char) * (len1 + len2 + 2));
	if (rep == NULL)
		return (NULL);
	for (i = 0; key[i] != '\0'; i++)
		rep[i] = key[i];
	rep[i] = '=';
	for (j = 0; value[j] != '\0'; j++)
		rep[i + 1 + j] = value[j];
	rep[i + 1 + j] = '\0';
	return (rep);
}

/**
 * _atoi - string into an integer func
 * @str: string to convert
 * Return: int value, or -1 if an error occurs
 */
int _atoi(char *str)
{
	unsigned int i, dig;
	int num = 0, num_t;

	num_t = INT_MAX;
	for (dig = 0; num_t != 0; dig++)
		num_t /= 10;
	for (i = 0; str[i] != '\0' && i < dig; i++)
	{
		num *= 10;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if ((i == dig - 1) && (str[i] - '0' > INT_MAX % 10))
			return (-1);
		num += str[i] - '0';
		if ((i == dig - 2) && (str[i + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (i > dig)
		return (-1);
	return (num);
}
