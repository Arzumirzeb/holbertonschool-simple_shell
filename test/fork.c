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
    pid_t first_pid = getpid();
    printf("Parent pid%u\nCurrent Pid %u\n", getppid(), getpid());

    printf("Before fork\n");
    pid = fork();
    if (pid == first_pid + 1)
	    pid = fork();
    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    return (0);
}
