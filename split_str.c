#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - entry point
 * @ac: number of arg values
 * @av: array of values
 *
 * Return: 0 on success
 */

int  main(int ac, char **av)
{
	char *str, *word;
	char **arr;
	int i, k;

	if (ac != 3)
	{
		perror("Error:");
		return (-1);
	}

	str = strdup(av[1]);

	word = strtok(str, av[2]);

	if (word != NULL)
	{
		arr = malloc(sizeof(char *) * 1);

		if (arr == NULL)
		{
			free(arr);
			return (-1);
		}
	}

	for (i = 0; 1; i++)
	{
		arr[i] = word;

		word = strtok(NULL, av[2]);
		if (word != NULL)
			arr = (char **) realloc(arr, sizeof(char *) * 1);
		else
			break;
	}

	for (k = 0; k <= i; k++)
	{
		printf("%s\n", arr[k]);
	}

	return (0);
}
