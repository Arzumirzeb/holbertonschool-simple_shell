#include "header.h"

/**
 * _split - splits given string into array
 * @str: string to split
 * @delim: separator, delimiter
 *
 * Return: pointer to two dimensional array on Success
 */

char **_split(char *str, char *delim)
{
	char *word;
	char **arr = malloc(strlen(str) * sizeof(char *));
	int i = 0;

	word = strtok(str, delim);

	while (word != NULL)
	{
		arr[i] = strdup(word);

		if (arr[i] == NULL)
		{
			free(arr[i]);
			exit(1);
		}
		i++;
		word = strtok(NULL, delim);
	}
	arr[i] = NULL;
	return (arr);
}
