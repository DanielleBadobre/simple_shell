#include "unixshell.h"

int main(void)
{
	while (TRUE)
	{
		char *line = NULL;
		size_t len = 0;

		if (isatty(STDIN_FILENO))
			print("$ ");

		if (getline(&line, &len, stdin) == -1)
		{
			putchar(10);
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (line[0] != '\n')
		{
			line[strcspn(line, "\n")] = '\0';
			execute_command(line);
		}
		free(line);
	}
	return 0;
}
