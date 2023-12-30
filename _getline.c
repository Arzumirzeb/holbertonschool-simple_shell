#include "header.h"

/**
 * _getline - function to implement getline
 *
 * Return: pointer to buffer on Success, NULL on fail
 */

char *_getline(void)
{
	char *line = NULL;
	size_t size = 0;
	int checker;

	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
	checker = getline(&line, &size, stdin);
	if (checker == -1)
		free(line);
	else
		return (line);
	return (NULL);
}
