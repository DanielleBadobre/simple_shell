#include "unixshell.h"

/**
 * read_input - a function to read input from the command line
 * @linebuff: a pointer to char * buffer
 * @n: holds the size of buffer pointer to by linebuff
 * @len: stores the character
 *
 * Return: number of byte read
 */

size_t read_input(char **linebuff, size_t *n, size_t *len)
{
	int c;
	ssize_t byte_read = 0;
	*n = 0;
	size_t buff_size = BUFFER_SIZE;

	*linebuff = (char *)malloc(buff_size);
	if (*linebuff == NULL)
	{
		perror("malloc");
		return (-1);
	}

	while ((byte_read = read(STDIN_FILENO, &c, 1)) != -1)
	{
		(*linebuff)[(*len)++] = c;
		if (*len >= buff_size)
		{
			buff_size += BUFFER_SIZE;
			*linebuff = (char *)realloc(*linebuff, buff_size);
			if (*linebuff == NULL)
			{
				perror("realloc");
				free(*linebuff);
				return (-1);
			}
		}

		if (c == '\n')
			break;
	}

	return (byte_read);
}
/**
 * handle_eof_or_error - a function to handle error
 * @linebuff: a pointer to a char * buffer
 * @byte_read: the byte read
 * @len: the characters
 *
 * Return: 0 success -1, Failure
 **/

size_t handle_eof_or_error(char **linebuff, ssize_t byte_read, size_t len)
{
	(*linebuff)[len] = '\0';

	if (byte_read == -1)
	{
		perror("read");
		free(*linebuff);
		return (-1);
	}
	if (len == 0 && byte_read == 0)
		return (-1);

	return (len);
}

/**
 * _getline - a function to read an entire line of text from stdin
 * @linebuff: a pointer to char * that stores the text
 * @n: the size of linebuff
 *
 * Return: Characters read
 **/
size_t _getline(char **linebuff, size_t *n)
{
	size_t len = 0;
	ssize_t byte_read;

	fflush(stdout);

	byte_read = read_input(linebuff, n, &len);
	if (byte_read == -1)
		return (-1);

	return (handle_eof_or_error(linebuff, byte_read, len));
}

