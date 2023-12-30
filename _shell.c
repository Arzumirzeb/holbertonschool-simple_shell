#include "header.h"
/**
 * main - main func
 *
 *Return: int
 */
int main(void)
{
	char *line;
	int status;

	while (1)
	{
		line = _getline();
		if (line == NULL)
			break;
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0);
		}
		status = execute(line);
		if (status == 2)
		{
			exit(2);
		}
	}
	return (status);
}
