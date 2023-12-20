#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
	char str[] = "Hello World";
	int a = strlen(str);
	char delim[] = " ";
	char *ptr = strtok(str, delim);

	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, delim);
	}
	for (int i = 0; i < a; i++)
	{
		if (str == '\0')
			printf("\\0\n");
		else
			printf("%c\n", str[i]);
	}
	return (0);
}
