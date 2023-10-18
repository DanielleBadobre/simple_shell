#include "unixshell.h"

/**
 * main - the entry point of every program
 * @argc: argument count
 * @argv: argument vector
 * @env: environmental variable
 *
 * Return: On success 0
 **/

int main(int argc, char *argv[], char **env)
{
	char *line = NULL;

	size_t len = 0;

	argc = 0;

	while (TRUE)
	{
		argc++;

		if (isatty(STDIN_FILENO))
			print("$ ");

		signal(SIGINT, signal_input);

		if (getline(&line, &len, stdin) == -1)
		{
			putchar(10);
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (line[0] != '\n')
		{
			line[strcspn(line, "\n")] = '\0';
			execute_command(line, argc, argv[0], env);
		}
	}

	free(line);
	return (0);
}
