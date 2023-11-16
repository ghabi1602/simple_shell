#include "shell.h"

/**
 * exe_path - executes cmd in path
 * @cmd: command path
 * @data: pointer to shell data
 *
 * Return: 0 on success, 1 otherwise.
 */
int exe_path(char *cmd, sh_data *data)
{
	pid_t child_pid;

	if (access(cmd, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			print_err(data, NULL);
		if (child_pid == 0)
		{
			if (execve(cmd, data->exp, data->env) == -1)
				print_err(data, NULL);
		}
		else
		{
			wait(&data->status);
			if (WIFEXITED(data->status))
				data->status = WEXITSTATUS(data->status);
			else if (WIFSIGNALED(data->status) && WTERMSIG(data->status) == SIGINT)
				data->status = 130;
			return (0);
		}
		data->status = 127;
		return (1);
	}
	else
	{
		print_err(data, ": Permission denied\n");
		data->status = 126;
	}
	return (0);
}

/**
 * path_hnd - finds the path variable
 * @env: environment variables
 *
 * Return: pointer to  node of path, or NULL on failure
 */
char *path_hnd(char **env)
{
	char *_path = "PATH=";
	unsigned int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (_path[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	return (env[i]);
}
/**
 * check_file - checks if the command is in the PATH
 * @data: pointer to shell data
 */
void check_file(sh_data *data)
{
	char *path, *path_cpy = NULL, *chk = NULL;
	unsigned int i = 0, n = 0;
	char **path_tok;
	struct stat buf;

	if (check_for_fld(data->exp[0]))
		n = exec_pwd_cmd(data);
	else
	{
		path = path_hnd(data->env);
		if (path != NULL)
		{
			path_cpy = _strdup(path + 5);
			path_tok = parse_func(path_cpy, ":");
			for (i = 0; path_tok && path_tok[i]; i++, free(chk))
			{
				chk = _strcat(path_tok[i], data->exp[0]);
				if (stat(chk, &buf) == 0)
				{
					n = exe_path(chk, data);
					free(chk);
					break;
				}
			}
			free(path_cpy);
			if (path_tok == NULL)
			{
				data->status = 127;
				c_exit(data);
			}
		}
		if (path == NULL || path_tok[i] == NULL)
		{
			print_err(data, ": Not found\n");
			data->status = 127;
		}
		free(path_tok);
	}
	if (n == 1)
		c_exit(data);
}

/**
 * exec_pwd_cmd - executes the command in cwd
 * @data: pointer to shell data
 * Return: 0 on success, 1 on failure
 */

int exec_pwd_cmd(sh_data *data)
{
	pid_t child_pid;
	struct stat buf;

	if (stat(data->exp[0], &buf) == 0)
	{
		if (access(data->exp[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
				print_err(data, NULL);
			if (child_pid == 0)
			{
				if (execve(data->exp[0], data->exp, data->env) == -1)
					print_err(data, NULL);
			}
			else
			{
				wait(&data->status);
				if (WIFEXITED(data->status))
					data->status = WEXITSTATUS(data->status);
				else if (WIFSIGNALED(data->status) && WTERMSIG(data->status) == SIGINT)
					data->status = 130;
				return (0);
			}
			data->status = 127;
			return (1);
		}
		else
		{
			print_err(data, ": Permission denied\n");
			data->status = 126;
		}
		return (0);
	}
	print_err(data, ": Not found\n");
	data->status = 127;
	return (0);
}

/**
 * check_for_fld - checks if the command is valid
 * @str: command
 *
 * Return: 1 on success, 0 on failure
 */
int check_for_fld(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}
