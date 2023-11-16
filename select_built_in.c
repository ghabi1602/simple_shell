#include "shell.h"

/**
 * select_builtins - checks if the command is a builtin
 * @data: shell _data struct pointer
 *
 * Return: returns pointer to a function
 */
void (*select_builtins(sh_data * data))(sh_data * data)
{
	unsigned int i;
	exec_blt func_arr[] = {
		{"exit", c_exit},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; func_arr[i].f != NULL; i++)
	{
		if (_strcmp(data->exp[0], func_arr[i].s) == 0)
			break;
	}
	if (func_arr[i].f != NULL)
		func_arr[i].f(data);
	return (func_arr[i].f);
}

/**
 * c_exit - exit program
 * @data: shell data
 */
void c_exit(sh_data *data)
{
	int status;

	if (_strcmp(data->exp[0], "exit") == 0 && data->exp[1] != NULL)
	{
		status = _atoi(data->exp[1]);
		if (status == -1)
		{
			data->status = 2;
			print_err(data, ": Illegal number: ");
			_print_err(data->exp[1]);
			_print_err("\n");
			free(data->ptr_cmd);
			data->ptr_cmd = NULL;
			return;
		}
		data->status = status;
	}
	free(data->buf);
	free(data->exp);
	free(data->ptr_cmd);
	free_envr(data->env);
	exit(data->status);
}

/**
 * _env - prints the current environment
 * @data: pointer to shell dat
 */
void _env(sh_data *data)
{
	unsigned int k;

	for (k = 0; data->env[k]; k++)
	{
		_print(data->env[k]);
		_print("\n");
	}
	data->status = 0;
}

/**
 * _setenv - edits the copied variable
 * @data: ptr to shell data
 *
 * Return: void
 */
void _setenv(sh_data *data)
{
	char **key;
	char *var;

	if (data->exp[1] == NULL || data->exp[2] == NULL)
	{
		print_err(data, ": Incorrect number of arguments\n");
		data->status = 2;
		return;
	}
	key = search_key(data->env, data->exp[1]);
	if (key == NULL)
		insert_key(data);
	else
	{
		var = insert_value(data->exp[1], data->exp[2]);
		if (var == NULL)
		{
			print_err(data, NULL);
			free(data->buf);
			free(data->ptr_cmd);
			free(data->exp);
			free_envr(data->env);
			exit(127);
		}
		free(*key);
		*key = var;
	}
	data->status = 0;
}

/**
 * _unsetenv - delete an env variable
 * @data: pointer to shell data
 *
 * Return: void
 */
void _unsetenv(sh_data *data)
{
	char **key, **envcpy;

	unsigned int i, j;

	if (data->exp[1] == NULL)
	{
		print_err(data, ": Incorrect number of arguments\n");
		data->status = 2;
		return;
	}
	key = search_key(data->env, data->exp[1]);
	if (key == NULL)
	{
		print_err(data, ": No variable to unset");
		return;
	}
	for (i = 0; data->env[i] != NULL; i++)
		;
	envcpy = malloc(sizeof(char *) * i);
	if (envcpy == NULL)
	{
		print_err(data, NULL);
		data->status = 127;
		c_exit(data);
	}
	for (i = 0; data->env[i] != *key; i++)
		envcpy[i] = data->env[i];
	for (j = i + 1; data->env[j] != NULL; j++, i++)
		envcpy[i] = data->env[j];
	envcpy[i] = NULL;
	free(*key);
	free(data->env);
	data->env = envcpy;
	data->status = 0;
}
