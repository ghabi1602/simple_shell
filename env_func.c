#include "shell.h"

/**
 * env_cpy - copies the env in main
 * @env: environment 
 *
 * Return: new env
 */

char **env_cpy(char **env)
{
	char **env_cpy = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	env_cpy = malloc(sizeof(char *) * (i + 1));
	if (env_cpy == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		env_cpy[i] = _strdup(env[i]);
	env_cpy[i] = NULL;
	return (env_cpy);
}

/**
 * free_env - free  environment
 * @env:  environment
 *
 * Return: void
 */

void free_envr(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
