#include "header.h"
#include <sys/wait.h>

/**
 * main - entry point
 * @ac: count of arguments
 * @av: array of arguments values
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char **argv;
	char *line, *cp_line;
	int status, i;
	pid_t fork_id;
	(void)ac;

	while (1)
	{
		line = NULL;
		if (_getline(&line) < 0)
		{
			free(line);
			exit(0);
		}
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		cp_line = strdup(line);
		free(line);
		argv = _split(cp_line, " \n\t");

		fork_id = fork();
		if (fork_id == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				free(argv);
				fprintf(stderr, "%s: %s\n", av[0], strerror(errno));
			}
			exit(1);
		}
		else
		{
			wait(&status);
		}
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
	}
	free(cp_line);
	free(line);
	return (0);
}
