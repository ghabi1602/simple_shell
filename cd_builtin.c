#include "shell.h"

/**
 * _pwd - prints the current working directory
 */

void _pwd()
{
	char buf[PATH_MAX];

	getcwd(buf, sizeof(buf));
	_print(buf);
}

/**
 * cd_to - changes to a given dir
 * @environ: takes in the environment
 * @cmd_arr: the args of the input
 */

void cd_to(char *cmd_arr[])
{
	char buf[PATH_MAX]; /* holds the cwd */
	char *dir_name, *cwd_cpy, *dir_cpy;

	getcwd(buf, sizeof(buf));

	cwd_cpy = _strdup(buf);

	dir_name = cmd_arr[1];
	if (chdir(dir_name) == -1)
	{
		perror("cd");
		return;
	}

	dir_cpy = _strdup(dir_name);
	setenv("OLDPWD", cwd_cpy, 1);
	setenv("PWD", dir_cpy, 1);

	free(cwd_cpy);
	free(dir_cpy);

	chdir(dir_name);
}

/**
 * cd_prev - change to the previous directory
 * @environ: the shell environ
 * Return: no return
 */

int cd_prev()
{
	char buf[PATH_MAX];
	char *cwd_cpy, *p_old, *old_cwd, *old_cwd_cpy;

	getcwd(buf, sizeof(buf));
	cwd_cpy = _strdup(buf);

	old_cwd = getenv("OLD_PWD");
	if (old_cwd == NULL)
		old_cwd = cwd_cpy;
	else
		old_cwd_cpy = _strdup(old_cwd);
	setenv("OLD_PWD", cwd_cpy, 1);

	if (chdir(old_cwd_cpy) == -1)
		setenv("PWD", cwd_cpy, 1);
	else
		setenv("PWD", old_cwd_cpy, 1);

	p_old = getenv("PWD");

	free(cwd_cpy);
	if (old_cwd)
		free(old_cwd_cpy);

	chdir(p_old);
	return (0);
}
