#include "header.h"
#include <sys/wait.h>

/**
 * main - entry point
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char **argv;
	char *line, *cp_line;
	int i, j, if_read_fail, status;
	pid_t fork_id;
	(void)ac;

	while (1)
	{
		line = NULL;
		if_read_fail = _getline(&line);

		if (if_read_fail == -1)
		{
			free(line);
			exit(0);
		}

		cp_line = strdup(line);
		free(line);
		argv = _split(cp_line, " ");

		if (argv == NULL)
			exit(1);

		if (argv[0][0] == '\n')
		{
			//free_twod_array(argv);
			free(argv);
			continue;
		}

		for (i = 0; argv[i + 1] != NULL; i++);

		for (j = 0; argv[i][j] != '\n'; j++);

		argv[i][j] = '\0';

		fork_id = fork();

		if (fork_id == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				//free_twod_array(argv);
				free(argv);
				fprintf(stderr, "%s: %s\n", av[0], strerror(errno));
			}
		}
		else
		{
			//free_twod_array(argv);
			free(argv);
			wait(&status);
		}
	}


	return (0);
}
