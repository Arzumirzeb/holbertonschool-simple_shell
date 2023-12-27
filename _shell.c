#include "header.h"
#include <sys/wait.h>

/**
 * main - entry point
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char **argv = NULL;
	int i, j, status;
	pid_t fork_id;
	(void)ac;

	while (1)
	{
		j = _getline(argv);

		if (j < 0)
			break;

		if (argv[0][0] == '\n')
			continue;

		for (i = 0; argv[i + 1] != NULL; i++);

		for (j = 0; argv[i][j] != '\n'; j++);

		argv[i][j] = '\0';

		fork_id = fork();

		if (fork_id == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				fprintf(stderr, "%s: %s\n", av[0], strerror(errno));
			}
		}
		else
			wait(&status);
	}


	return (0);
}
