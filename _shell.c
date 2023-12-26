#include "header.h"
#include <sys/wait.h>

/**
 * main - entry point
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	char **argv;
	int i, j, status;
	pid_t fork_id;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		j = getline(&line, &len, stdin);

		if (j == -1)
			break;

		argv = malloc(sizeof(char *) * 2);

		if (argv == NULL)
		{
			free(argv);
			return (-1);
		}

		argv[0] = malloc(sizeof(char) * len + 1);

		if (argv[0] == NULL)
		{
			free(argv[0]);
			free(argv);
			break;
		}

		argv[0] = line;

		if (argv[0][0] == '\n')
			continue;

		for (i = 0; argv[0][i] != '\n'; i++);

		argv[0][i] = '\0';
		argv[1] = NULL;

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
