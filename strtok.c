#include "unixshell.h"

char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int pos = 0;
	int c;

	/* Read characters from stdin until a newline or EOF is encountered */
	while ((c = getchar()) != EOF && c != '\n')
	{
		/* Add the character to the buffer if there is space */
		if (pos < (BUFFER_SIZE - 1))
			buffer[pos++] = c;
	}

	/* Add a null terminator to the end of the buffer */
	buffer[pos] = '\0';
	pos = 0;

	return buffer;
}

int main()
{
	char *line;
	while (1)
	{
		printf("> ");
		line = custom_getline();
		while (*line)
		{
			putchar(*line);
			line++;
		}
		putchar(10);
	}

	return 0;
}
