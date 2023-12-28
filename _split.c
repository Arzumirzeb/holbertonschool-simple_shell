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
	char **arr;
	int i;

	word = strtok(str, delim);

	if (word != NULL)
	{
		arr = (char **)malloc(sizeof(char *) * 2);

		if (arr == NULL)
		{
			free(arr);
			exit(1);
		}
	}

	for (i = 0; 1; i++)
	{
		arr[i] = word;
		arr[i + 1] = NULL;

		word = strtok(NULL, delim);
		if (word != NULL)
		{
			arr = (char **) realloc(arr, sizeof(char *) * (i + 3));
			if (arr == NULL)
			{
				free(arr);
				exit(1);
			}
		}
		else
			break;
	}

	return (arr);
}
