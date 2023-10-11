#include "unixshell.h"

ssize_t _getline(char **linebuff, size_t *n)
{
    int c;
    ssize_t byte_read = 0, buff_size, len = 0;
    *n = 0;
    buff_size = *n;
    *linebuff = NULL;

    fflush(stdout);

    if (*linebuff == NULL || *n == 0)
    {
        buff_size = BUFFER_SIZE;
        *linebuff = (char *)malloc(buff_size);
        if (*linebuff == NULL)
        {
            perror("malloc");
            return (-1);
        }
    }
    while ((byte_read = read(STDIN_FILENO, &c, 1)) != -1)
    {
        (*linebuff)[len++] = c;
        if (len >= buff_size)
        {
            buff_size += BUFFER_SIZE;
            *linebuff = (char *)realloc(*linebuff, *n);
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
