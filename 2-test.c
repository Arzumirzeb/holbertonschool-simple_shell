#include <stdio.h>
#include <unistd.h>
int main()
{
	char *promt = NULL;
	size_t n = 0;

	printf("$ ");
	getline(&promt, &n, stdin);
	printf("%s", promt);
	return (0);
}
