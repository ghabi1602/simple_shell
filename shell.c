#include "shell.h"

/**
 * sig_handler - handles ^C signal
 * @unused: unused variable
 */
static void sig_handler(int unused)
{
	(void) unused;
	if (flag == 0)
		_print("\n$ ");
	else
		_print("\n");
}

/**
 * main - shell main
 * @argc: args count
 * @argv: args vector
 * @environment: shell env
 * Return: 0 or exit status
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t buf_len = 0;
	unsigned int i_pipe = 0, i;
	sh_data data = {NULL, NULL, NULL, NULL, NULL, 0, 0};

	data.argv = argv;
	data.env = env_cpy(environment);
	signal(SIGINT, sig_handler);
	if (!isatty(STDIN_FILENO))
		i_pipe = 1;
	if (i_pipe == 0)
		_print("$ ");
	flag = 0;
	while (getline(&(data.buf), &buf_len, stdin) != -1)
	{
		flag = 1;
		data.num++;
		data.ptr_cmd = parse_func(data.buf, ";");
		for (i = 0; data.ptr_cmd && data.ptr_cmd[i] != NULL; i++)
		{
			data.exp = parse_func(data.ptr_cmd[i], "\n \t\r");
			if (data.exp && data.exp[0])
				if (select_builtins(&data) == NULL)
					check_file(&data);
			free(data.exp);
		}
		free(data.buf);
		free(data.ptr_cmd);
		flag = 0;
		if (i_pipe == 0)
			_print("$ ");
		data.buf = NULL;
	}
	if (i_pipe == 0)
		_print("\n");
	free_envr(data.env);
	free(data.buf);
	exit(data.status);
}
