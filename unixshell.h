#ifndef GATES_OF_SHELL
#define GATES_OF_SHELL

#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define TRUE 1
#define BUFFER_SIZE 4321
size_t _getline(char **linebuff, size_t *n);
size_t handle_eof_or_error(char **linebuff, ssize_t byte_read, size_t len);
size_t read_input(char **linebuff, size_t *n, size_t *len);
char *_strtok(char *str, const char *delim, char **saveptr);
char *_strchr(const char *s, char c);

#endif
