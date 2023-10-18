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

	static	int c;
	ssize_t byte_read;
	size_t i = 0;

	memalloc(linebuff, n);

	while ((byte_read = read(STDIN_FILENO, &c, 1)) > 0)
	{
		(*linebuff)[i] = c;
		if (c == '\n')
		{
			(*linebuff)[i] = '\0';
			return (i);
		}

		i++;
		if (i >= *n)
		{
			*n += BUFFER_SIZE; /* Increase the buffer size */
			*linebuff = (char *)realloc(*linebuff, *n);
			if (*linebuff == NULL)
			{
				perror("realloc");
				return (-1);
			}
		}
	}
	if (byte_read == -1)
	{
		perror("read");
		free(*linebuff);
		return (-1);
	}
	(*linebuff)[i] = '\0';

	if (i == 0 && byte_read == 0)
		return (-1); /* No characters read, reached EOF */

	return (i);
}

/**
 * memalloc- a function to allocate memory
 * @linebuff: a pointer to char *
 * @n: the unsigned int size
 *
 * Return: On success, 1, otherwise -1
 **/

int memalloc(char **linebuff, size_t *n)
{
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

	return (1);
}
