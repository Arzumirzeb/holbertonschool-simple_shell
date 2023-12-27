#include "header.h"

/**
 * _split - splits given string into array
 * @str: string to split
 * @delim: separator, delimiter
 *
 * Return: pointer to two dimensional array
 */

char **_split(char *str, char *delim)
{
	char *cp_str, *word;
	char **arr;
	int i;

	cp_str = strdup(str);

	word = strtok(cp_str, delim);

	if (word != NULL)
	{
		arr = malloc(sizeof(char *) * 1);

		if (arr == NULL)
		{
			free(arr);
			return (NULL);
		}
	}

	for (i = 0; 1; i++)
	{
		arr[i] = word;

		word = strtok(NULL, delim);
		if (word != NULL)
		{
			arr = (char **) realloc(arr, sizeof(char *) * 1);
			if (arr == NULL)
			{
				free(arr);
				return (NULL);
			}
		}
		else
			break;
	}

	arr = (char **) realloc(arr, sizeof(char *) * 1);
	arr[i + 1] = NULL;

	return (arr);
}
