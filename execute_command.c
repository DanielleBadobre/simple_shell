#include "unixshell.h"

void execute_command(char *line)
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
		if (chdir(cmd_arg[1]) != 0)
			perror("cd");
		return;
	}
	if (_strcmp(cmd_arg[0], "exit") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
			
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(cmd_arg[0], cmd_arg, NULL) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
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
