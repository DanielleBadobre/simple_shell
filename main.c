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

		if (_getline(&line, &len) == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (line[0] != '\n')
		{
			line[_strcspn(line, "\n")] = '\0';
			execute_command(line, argc, argv[0], env);
		}
	}

	free(line);
	return (0);
}

/**
 * _strcspn- a function calculate the length of an initial segment of a string
 * that consists entirely of provide characters
 * @str1: the first string
 * @str2: the target string
 *
 * Return: the length
 **/
size_t _strcspn(const char *str1, const char *str2)
{

	size_t i, j;

	for (i = 0; str1[i] != '\0'; i++)
	{
		for (j = 0; str2[j] != '\0'; j++)
		{
			if (str1[i] == str2[j])
				return (i);
		}
	}

	return (i);
}
