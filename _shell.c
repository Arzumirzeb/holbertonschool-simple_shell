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
	char *line;
	int status, i;
	pid_t fork_id;
	(void)ac;

	while (1)
	{
		line = _getline();
		if (!line)
			break;

		argv = _split(line, " \n\t");
		free(line);
		
		if (!*argv)
		{
			free(argv);
			continue;
		}
		if (access(argv[0], X_OK) == -1)
		{
			fprintf(stderr, "%s: command not found\n", argv[0]);
			free(argv);
			continue;
		}
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
	free(line);
	return (0);
}
