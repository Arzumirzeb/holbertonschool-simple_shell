#include "header.h"
#include <sys/wait.h>

/**
 * create_full_path - creates full path from single command
 * @command: single command
 */

void create_full_path(char **command)
{
	int length_command = strlen(*command);
	char *tmp, *single_path, *path;
	size_t size_tmp;

	path = strdup(getenv("PATH"));
	single_path = strtok(path, ":");

	while (single_path != NULL)
	{
		size_tmp = strlen(single_path) + length_command + 2;
		tmp = malloc(sizeof(char) * size_tmp);

		if (tmp == NULL)
		{
			free(tmp);
			return;
		}

		strcpy(tmp, single_path);
		strcat(tmp, "/");
		strcat(tmp, *command);

		if (access(tmp, X_OK) == -1)
		{
			free(tmp);
			single_path = strtok(NULL, ":");
		}
		else
		{
			free(*command);
			*command = tmp;
			return;
		}
	}
}


/**
 * main - entry point
 * @ac: count of arguments
 * @av: array of arguments values
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char **argv, *line;
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

		create_full_path(&argv[0]);
		fork_id = fork();
		if (fork_id == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				for (i = 0; argv[i]; i++)
					free(argv[i]);
				free(argv);
				fprintf(stderr, "%s: %s\n", av[0], strerror(errno));
			}
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
	}
	free(line);
	return (0);
}
