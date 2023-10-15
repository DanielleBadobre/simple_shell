#include "unixshell.h"

int main(void)
{
	char *line = NULL;
	
	size_t len = 0;
	int count = 0;
	while (TRUE)
	{

		count++;

		if (isatty(STDIN_FILENO))
			print("$ ");

		if (_getline(&line, &len) == -1)
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
	}

	free(line);
	return (0);
}
