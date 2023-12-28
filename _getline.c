#include "header.h"

/**
 * _getline - creates command array based on input
 * @argv: pointer to 2D array
 *
 * Return: 1 on Success, -1 on fail
 */

int _getline(char **line)
{
	size_t len = 0;

	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");

	if (getline(line, &len, stdin) == -1)
	{
		return(-1);
	}

	return (1);
}
