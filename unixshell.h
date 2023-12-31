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
#include <string.h>
#include <errno.h>

#define TRUE 1
#define BUFFER_SIZE 12
#define DELIM " \n\t"

char *_strtok(char *str, const char *delim, char **saveptr);
char *_strchr(const char *s, char c);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int memalloc(char **linebuff, size_t *n);
int _putchar(char c);
int print(char *str);
int _atoi(char *s);
int change_dir(const char *path_name);

void msgerror(char *name, int fact, char **cmd_opt);
void signal_input(int signal);
void handle_exec(char *cmd_arg[], int count, char *filename, char **env);
void execute_command(char *line, int count, char *filename, char **env);
void print_env(char **env);
void handle_exit(char *cmd_arg[], char *line, int count, char *filename);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

ssize_t _getline(char **linebuff, size_t *n);

size_t _strcspn(const char *str1, const char *str2);
#endif
