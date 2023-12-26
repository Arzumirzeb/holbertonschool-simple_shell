#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t pid;

    printf("%u\n", getpid());
    pid = fork();
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    return (0);
}
