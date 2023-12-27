#include "header.h"

/**
 * _getline - creates command array based on input
 * @argv: pointer to 2D array
 *
 * Return: 1 on Success, -1 on fail
 */

int _getline(char **argv)
{
	char *line = NULL;
	int j; 
	size_t len = 0;

	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
	j = getline(&line, &len, stdin);

	if (j == -1)
	{
		free(line);
		return (-1);
	}

	argv = _split(line, " ");
	
	return (1);
}
