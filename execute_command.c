#include "unixshell.h"

/**
 * handle_exec- a function that searches for and execute an executable files
 *
 * @cmd_arg: command line arguments
 * @count: the number of processes per loop
 * @filename: the name of executable files
 * @env: environmental variable
 *
 * Return: nothing
 **/

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

/**
 * handle_exit- a function that exits the program
 *
 * @cmd_arg: command line arguments
 * @line: the  buffer
 * @count: the number of processes per loop
 * @filename: the name of executable files
 *
 * Return: nothing
 **/

void handle_exit(char *cmd_arg[], char *line, int count, char *filename)
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

/**
 * execute_command- a function that executes commands
 *
 * @line: the buffer
 * @count: the number of processes per loop
 * @filename: the name of executable files
 * @env: environmental variable
 *
 * Return: nothing
 **/

void execute_command(char *line, int count, char *filename, char **env)
{
	char *token, *saveptr, *cmd_arg[BUFSIZ] = {NULL};
	int status, i = 0;
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

	handle_exit(cmd_arg, line, count, filename);

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
		if (_strchr(cmd_arg[0], '/') == NULL)
			handle_exec(cmd_arg, count, filename, env);

		else if (execve(cmd_arg[0], cmd_arg, env) == -1)
		{
			msgerror(filename, count, cmd_arg);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid < 0)
		msgerror(filename, count, cmd_arg);
	else
		wait(&status);
}

/**
 * _strcpy- copies the string pointed to by src,
 * including the terminating null byte to the buffer pointed to by dest.
 *
 * @dest: destination
 * @src: source
 * Return: the pointer to dest
 *
 **/

char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}
