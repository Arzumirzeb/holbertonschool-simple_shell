#include "header.h"
#include <sys/wait.h>

/**
 * create_full_path - creates full path from single command
 * @command: single command
 * @program_name: name of the program
 *
 * Return: 0 on success, -1 on fail
 */

int create_full_path(char **command, char *program_name)
{
	int length_command = strlen(*command);
	char *tmp, *single_path, *path;
	size_t size_tmp;

	path = strdup(getenv("PATH"));
	if (path == NULL || strlen(path) == 0)
	{
		free(path);
		fprintf(stderr, "%s: 1: %s not found \n", program_name, *command);
		return (-1);
	}
	single_path = strtok(path, ":");
	while (single_path != NULL)
	{
		size_tmp = strlen(single_path) + length_command + 2;
		tmp = malloc(sizeof(char) * size_tmp);
		if (tmp == NULL)
		{
			free(path);
			free(tmp);
			return (-1);
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
			free(path);
			free(*command);
			*command = tmp;
			return (0);
		}
	}
	free(path);
	return (0);
}

/**
 * free_array - frees elements of array not array itself
 * @arr: 2d array
 */

void free_array(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
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
	int status;
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
<<<<<<< HEAD
		if (access(argv[0], X_OK) == -1)
		{
			fprintf(stderr, "%s: command not found\n", argv[0]);
			free(argv);
			continue;
		}
=======
		if (create_full_path(&argv[0], av[0]) == -1)
		{
			free_array(argv);
			exit(127);
		}

>>>>>>> be270ac1c176b711a1eb999fe175051de099c9e1
		fork_id = fork();
		if (fork_id == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				free_array(argv);
				free(argv);
				fprintf(stderr, "%s: %s\n", av[0], strerror(errno));
			}
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
<<<<<<< HEAD
		}
		for (i = 0; argv[i]; i++)
			free(argv[i]);
	`	free(argv);
=======
		free_array(argv);
		free(argv);
>>>>>>> be270ac1c176b711a1eb999fe175051de099c9e1
	}
	return (0);
}
