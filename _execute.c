#include "header.h"
/**
 * execute - executes command
 *
 *@command: The command string to execute.
 *
 * Return: the exit status of the executed command,
 * or -1 if an error occurs.
 */
int execute(char *command)
{
        int status = 0;
        pid_t pid = fork();

        if (pid == -1)
        {
                perror("fork");
                free(str);
                exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
                char *arr[64];
                _split(str, delim);
                if (argv[0] == NULL)
                {
                        free(str);
                        exit(EXIT_SUCCESS);
                }
                if (strcmp(argv[0], "env") == 0)
                {
                        char **env = environ;

                        while (*env != NULL)
                        {
                                printf("%s\n", *env);
                                env++;
                        }
                        free(str);
                        exit(EXIT_SUCCESS);
                }
                if (strchr(argv[0], '/') != NULL)
                {
                        if (access(argv[0], X_OK) == 0)
                        {
                                if (execve(argv[0], argv, environ) == -1)
                                {
                                        perror("execve");
                                        free(str);
                                        exit(EXIT_FAILURE);
                                }
                        }
                }
                else
                {
                        char *path = getenv("PATH");
                        char *token;
                        if (path == NULL)
                        {
                                fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
                                free(str);
                                exit(127);
                        }
                        token = strtok(path, ":");
                        while (token != NULL)
                        {
                                char executable_path[256];
                                snprintf(executable_path, sizeof(executable_path), "%s/%s", token, arr[0]);
                                if (access(executable_path, X_OK) == 0)
                                {
                                        if (execve(executable_path, arr, environ) == -1)
                                        {
                                                perror("execve");
                                                free(str);
                                                exit(EXIT_FAILURE);
                                        }
                                }
                                token = strtok(NULL, ":");
                        }
                }
                fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
                free(str);
                exit(127);
        }
        else
        {
                waitpid(pid, &status, 0);
                free(str);
                if (WIFEXITED(status))
                        status = WEXITSTATUS(status);
                else
                        status = 1;
        }
        return (status);
}
