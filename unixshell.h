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



void execute_command(char *line, char **env);
void msgerror(char *name, int fact, char **cmd_opt);
void getpath(char **PATH);
void handle_cd_exit(char *cmd_arg[], char *line);
void handle_exec(char *cmd_arg[]);
void print_env(char **env);


ssize_t _getline(char **linebuff, size_t *n);
#endif
