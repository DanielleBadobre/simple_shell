#include "unixshell.h"

void handle_exec(char *cmd_arg[])
{
    char *path = getenv("PATH");
    char *saveptr;
    char *path_copy = _strdup(path);
    char *dir = _strtok(path_copy, ":", &saveptr);

    while (dir != NULL)
    {
        char *full_path = malloc(_strlen(dir) + _strlen(cmd_arg[0]) + 2);
        _strcpy(full_path, dir);
        _strcat(full_path, "/");
        _strcat(full_path, cmd_arg[0]);

        if (access(full_path, X_OK) == 0)
        {
            execve(full_path, cmd_arg, NULL);
            free(full_path);
            break;
        }
        free(full_path);
        dir = _strtok(NULL, ":", &saveptr);
    }

    free(path_copy);
    if (dir == NULL)
    {
        fprintf(stderr, "%s: command not found\n", cmd_arg[0]);
        exit(EXIT_FAILURE);
    }
}

void execute_command(char *line, char **env)
{
    char *token, *saveptr;
    char *cmd_arg[BUFSIZ] = {NULL};
    int i = 0;
    pid_t child_pid;

    token = _strtok(line, DELIM, &saveptr);

    while (token != NULL)
    {
        cmd_arg[i++] = token;
        token = _strtok(NULL, DELIM, &saveptr);
    }

    cmd_arg[i] = NULL;

    if (i == 0)
        return;

    if (_strcmp(cmd_arg[0], "cd") == 0)
    {
        if (cmd_arg[1] == NULL)
            chdir(getenv("HOME"));
        else
            chdir(cmd_arg[1]);
        return;
    }
    if (_strcmp(cmd_arg[0], "exit") == 0)
    {
        if (cmd_arg[1] != NULL)
        {
            int status = _atoi(cmd_arg[1]);
            if (status != 0)
            {
                free(line);
                exit(status);
            }
            else
            {
                write(STDERR_FILENO, "Usage: exit status", 19);
            }
        }
        free(line);
        exit(EXIT_SUCCESS);
    }

    if (_strcmp(cmd_arg[0], "env") == 0)
    {
        print_env(env);
    }

    child_pid = fork();
    if (child_pid == 0)
    {
        char c = '/';
        if (_strchr(cmd_arg[0], c) == NULL)
        {
            handle_exec(cmd_arg);
        }

        else
        {
            if (execve(cmd_arg[0], cmd_arg, NULL) == -1)
            {
                perror("execve failed");
                exit(EXIT_FAILURE);
            }
        }
    }

    else if (child_pid < 0)
        perror("fork failed");

    else
    {
        int status;
        wait(&status);
        if (WIFEXITED(status))
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        else
            perror("Child process did not exit normally");
    }
}
