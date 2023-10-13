#include "unixshell.h"

/**
 * main - Entry point of the program
 *
 * Return: On success, 0
 *
 **/

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t readline;
	char *token, *saveptr;
	char *dup;

	/*while (TRUE)*/
	{
		printf("$ ");
		fflush(stdout);

		readline = _getline(&line, &len);
		if (readline == -1)
		{
			perror("Unable to getline");
			return (-1);
		}

		dup = _strdup(line);

		token = _strtok(dup, " ", &saveptr);
		while (token != NULL)
		{
			printf("%s\n", token);
			token = _strtok(NULL, " ", &saveptr);
		}
		free(dup);
	}

	free(line);
	return (0);
}
