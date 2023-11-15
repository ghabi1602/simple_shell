#include "shell.h"

/**
 * cd_to - changes to a given dirt
 * @cmd_arr: the args of the input
 * Return: int
 */

int cd_to(char *cmd_arr[])
{
	char buf[PATH_MAX]; /* holds the cwd */
	char *dir_name, *cwd_cpy, *dir_cpy;

	getcwd(buf, sizeof(buf));

	cwd_cpy = _strdup(buf);

	dir_name = cmd_arr[1];
	if (chdir(dir_name) == -1)
	{
		perror("cd");
		return (-1);
	}

	dir_cpy = _strdup(dir_name);
	setenv("OLDPWD", cwd_cpy, 1);
	setenv("PWD", dir_cpy, 1);

	free(cwd_cpy);
	free(dir_cpy);

	chdir(dir_name);
	return (0);
}

/**
 * cd_prev - change to the previous directory
 * Return: no return
 */

int cd_prev(void)
{
	char buf[PATH_MAX];
	char *cwd_cpy, *p_old, *old_cwd, *old_cwd_cpy;

	getcwd(buf, sizeof(buf));
	cwd_cpy = _strdup(buf);

	old_cwd = getenv("OLDPWD");
	if (old_cwd == NULL)
		old_cwd = cwd_cpy;
	else
		old_cwd_cpy = _strdup(old_cwd);

	if (chdir(old_cwd_cpy) == -1)
		setenv("PWD", cwd_cpy, 1);
	else
		setenv("PWD", old_cwd_cpy, 1);

	p_old = getenv("OLDPWD");
	write(STDOUT_FILENO, p_old, _strlen(p_old));
	write(STDOUT_FILENO, "\n", 1);

	free(cwd_cpy);
	if (old_cwd)
		free(old_cwd_cpy);
	setenv("OLDPWD", buf, 1);
	chdir(old_cwd);

	return (1);
}

/**
 * cd_home - returns to $HOME
 * Return: retuns 1 on success and -1 on error
 */

int cd_home(void)
{
	char cwd[PATH_MAX];
	char *cwd_cpy, *home_d;

	getcwd(cwd, sizeof(cwd));
	cwd_cpy = _strdup(cwd);

	home_d = getenv("HOME");

	if (home_d == NULL)
	{
		setenv("OLDPWD", cwd_cpy, 1);
		free(cwd_cpy);
		return (1);
	}

	if (chdir(home_d) == -1)
	{
		perror("cd");
		free(home_d);
		return (-1);
	}

	setenv("OLDPWD", cwd_cpy, 1);
	setenv("PWD", home_d, 1);
	free(cwd_cpy);

	return (1);
}

/**
 * cd_back - returns to the parent directory
 * Return: returns 1 on succes and -1 on failure
 */

int cd_back(void)
{
	char cwd[PATH_MAX];
	char *cwd_cpy, *new_path;

	getcwd(cwd, sizeof(cwd));
	cwd_cpy = _strdup(cwd);

	new_path = strrchr(cwd_cpy, '/');

	if (new_path != NULL)
	{
		chdir(new_path);
		setenv("OLDPWD", cwd_cpy, 1);
		setenv("PWD", new_path, 1);
	}

	free(cwd_cpy);
	return (1);
}

/**
 * rm_cwd - removes a directory
 * @str: string
 * Return: pointer to a string
 */
char *rm_cwd(char *str)
{
	int i, j, len = _strlen(str);
	char *addr = NULL;

	for (i = len; i >= 0; i--)
	{
		if (str[i] == '/')
			break;
	}
	printf("i got her");

	for (j = 0; j <= i; j++)
	{
		addr[j] = str[j];
	}
	addr[j] = '\0';
	printf("%s\n", addr);

	return (addr);
}
