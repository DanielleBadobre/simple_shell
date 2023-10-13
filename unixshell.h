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
char *_strtok(char *str, const char *delim, char **saveptr);
char *_strchr(const char *s, char c);
ssize_t _getline(char **linebuff, size_t *n);
char *_strdup(char *str);

#endif
