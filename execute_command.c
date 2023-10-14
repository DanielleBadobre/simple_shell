#include "unixshell.h"

int execute_command(char *line, char *argv[])
{

	char *saveptr;
	char *token;
	char *dup = _strdup(line);

	token = _strtok(dup, DELIM, &saveptr);
	while (token != NULL)
	{
		pid_t child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(token, argv, NULL) == -1)
			{
				perror("execve failed");
				exit(EXIT_FAILURE);
			}
		}
		else if (child_pid < 0)
		{
			perror("fork failed");
		}
		else
		{
			int status;
			wait(&status);
			// if (WIFEXITED(status))
			// printf("Child process exited with status: %d\n", WEXITSTATUS(status));
			// else`
			// perror("Child process did not exit normally");
		}
		token = _strtok(NULL, DELIM, &saveptr);
	}

	free(dup);
	return 1;
}

