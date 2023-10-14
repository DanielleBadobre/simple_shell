#include "unixshell.h"

int main(int argc, char *argv[], char **env)
{
	(void)argc;
	char *line = NULL;
	size_t len = 0;
	ssize_t readline;
	char *token, *saveptr, *dup;
	pid_t pid;
	char *cmd_arg[] = {NULL, NULL};

//	while (TRUE)
	{
		print("$ ");
		fflush(stdout);

		readline = _getline(&line, &len);
		if (readline == -1)
		{
			_putchar(10);
			free(line);
			exit(EXIT_SUCCESS);
		}
		execute_command(line, argv);
	}
	free(line);
	return 0;
}
