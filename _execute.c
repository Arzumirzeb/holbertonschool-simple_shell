#include "header.h"
/**
 * execute - executes command
 *
 *@command: The command string to execute.
 *
 * Return: the exit status of the executed command,
 * or -1 if an error occurs.
 */
int execute(char *line)
{
        int status = 0;
        pid_t fork_id = fork();

        if (fork_id == -1)
        {
                perror("fork");
                free(line);
                exit(EXIT_FAILURE);
        }
        else if (fork_id == 0)
        {
                char *argv[64];
                line_div(str, delim);
                if (argv[0] == NULL)
                {
                        free(line);
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
                        free(line);
                        exit(EXIT_SUCCESS);
                }
                if (strchr(argv[0], '/') != NULL)
                {
                        if (access(argv[0], X_OK) == 0)
                        {
                                if (execve(argv[0], delim, environ) == -1)
                                {
                                        perror("execve");
                                        free(line);
                                        exit(EXIT_FAILURE);
                                }
                        }
                }
                else
                {
                        char *path = getenv("PATH");
                        char *word;
                        if (path == NULL)
                        {
                                fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
                                free(line);
                                exit(127);
                        }
                        word = strtok(path, ":");
                        while (word != NULL)
                        {
                                char executable_path[256];
                                snprintf(executable_path, sizeof(executable_path), "%s/%s", token, argv[0]);
                                if (access(executable_path, X_OK) == 0)
                                {
                                        if (execve(executable_path, delim, environ) == -1)
                                        {
                                                perror("execve");
                                                free(line);
                                                exit(EXIT_FAILURE);
                                        }
                                }
                                word = strtok(NULL, ":");
                        }
                }
                fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
                free(line);
                exit(127);
        }
        else
        {
                waitpid(fork_id, &status, 0);
                free(line);
                if (WIFEXITED(status))
                        status = WEXITSTATUS(status);
                else
                        status = 1;
        }
        return (status);
}
