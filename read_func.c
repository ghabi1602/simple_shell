#include "shell.h"

/**
* reader - the functions reads the intput from stdin
* @cmd: the commad from the user input
*/

char* reader()
{
	char *buffer = NULL;
	size_t count = 0;
	ssize_t read;

	read = getline(&buffer, &count, stdin);
	if (read == -1)
	{
		_print("coud not read line");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	buffer[strcspn(buffer, "\n")] = '\0';
	
	return (buffer);
}
