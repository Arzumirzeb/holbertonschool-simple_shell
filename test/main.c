#include "header.h"

/**
 * main - entry point
 *
 * Return: 0 on success
 */

int main(void)
{
	int i;
	char *str = "/bin/ls -l ./tmp";
	char **arr;

	arr = _split(str, " ");

	return (0);
}
