#include "unixshell.h"

void handle_exec(char *cmd_arg[], int count, char *filename, char **env)
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
            execve(full_path, cmd_arg, env);
            free(full_path);
            break;
        }
        free(full_path);
        dir = _strtok(NULL, ":", &saveptr);
    }

    free(path_copy);
     if (dir == NULL)
     {
         msgerror(filename, count, cmd_arg);
         exit(EXIT_FAILURE);
     }
}

void handle_cd_exit(char *cmd_arg[], char *line, int count, char *filename)
{

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
                msgerror(filename, count, cmd_arg);
        }
        free(line);
        exit(EXIT_SUCCESS);
    }    
}

void execute_command(char *line, int count, char *filename, char **env)
{
    char *token, *saveptr, *cmd_arg[BUFSIZ] = {NULL};
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

    handle_cd_exit(cmd_arg, line, count, filename);

    if (_strcmp(cmd_arg[0], "env") == 0)
        print_env(env);

    if (_strcmp(cmd_arg[0], "cd") == 0)
    {
        change_dir(cmd_arg[1]);
        return;
    }

        child_pid = fork();
        if (child_pid == 0)
        {
            char c = '/';
            if (_strchr(cmd_arg[0], c) == NULL)
                handle_exec(cmd_arg, count, filename, env);

            else if (execve(cmd_arg[0], cmd_arg, env) == -1)
            {
                msgerror(filename, count, cmd_arg);
                exit(EXIT_FAILURE);
            }
    }
    else if (child_pid < 0)
    {
        msgerror(filename, count, cmd_arg);
    }
    
    else
    {
        int status;
        wait(&status);
    }
}
