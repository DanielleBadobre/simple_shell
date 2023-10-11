#include "unixshell.h"


int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = _getline(&line, &len);

		if (read != -1)
		{
			printf("%s", line);
		}
		else
		{
			if (read == -1)
				printf("End of input reached (Ctrl+D).\n");
			else
				perror("_getline");
			break;
		}
	}

	free(line); // Don't forget to free the allocated memory

	return 0;
}
