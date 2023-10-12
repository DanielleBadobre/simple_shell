#include "unixshell.h"

/**
 * _getline - a function to read an entire line of text from stdin
 * @linebuff: a pointer to char * that stores the text
 * @n: the size of linebuff
 *
 * Return: Characters read
 **/

ssize_t _getline(char **linebuff, size_t *n)
{
	int c = 0;
	ssize_t byte_read;
	size_t i = 0;

	if (*linebuff == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*linebuff = (char *)malloc(*n);
		if (*linebuff == NULL)
		{
			perror("malloc");
			return (-1);
		}
	}
	while (c != EOF && c != '\n')
	{
		byte_read = read(STDIN_FILENO, &c, 1);
		if (byte_read == -1)
		{
			perror("Unable to read");
			return (-1);
		}
		(*linebuff)[i++] = c;
		if (i == *n)
		{
			*n += BUFFER_SIZE;
			char *temp = realloc(*linebuff, *n);

			if (temp == NULL)
			{
				perror("realloc");
				free(*linebuff);
				*linebuff = NULL;
				return (-1);
			}
			*linebuff = temp;
		}
	}
	(*linebuff)[i] = '\0';
	return (i);
}
