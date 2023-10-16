#include "unixshell.h"

void handle_exec(char *cmd_arg[], int line_count)
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
        fprintf(stderr, "./hsh: %d: %s: not found\n", line_count, cmd_arg[0]);
        return;
    }
}

void execute_command(char *line, char **env, int line_count)
{
    char *token, *saveptr;
    char *cmd_arg[BUFSIZ] = {NULL};
    int i = 0;

    token = _strtok(line, DELIM, &saveptr);

    while (token != NULL)
    {
        cmd_arg[i++] = token;
        token = _strtok(NULL, DELIM, &saveptr);
    }

    cmd_arg[i] = NULL;

    if (i == 0)
        return;

    handle_cd_exit(cmd_arg, line);

    handle_exec(cmd_arg, line_count);
}

void handle_cd_exit(char *cmd_arg[], char *line) {
    if (_strcmp(cmd_arg[0], "cd") == 0) {
        if (cmd_arg[1] == NULL)
            chdir(getenv("HOME"));
        else
            chdir(cmd_arg[1]);
    } else if (_strcmp(cmd_arg[0], "exit") == 0) {
        free(line);
        int exit_code = 0;
        if (cmd_arg[1] != NULL) {
            exit_code = atoi(cmd_arg[1]);
        }
        exit(exit_code);
    }
}
