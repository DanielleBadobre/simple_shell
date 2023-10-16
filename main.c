#include "unixshell.h"

int main(int argc, char *argv[], char **env)
{
    char *line = NULL;
    size_t len = 0;
    int line_count = 0;

    while (TRUE)
    {
        line_count++;

        if (isatty(STDIN_FILENO))
            print("$ ");

        if (_getline(&line, &len) == -1)
        {
            putchar(10);
            free(line);
            exit(EXIT_SUCCESS);
        }
        if (line[0] != '\n')
        {
            line[strcspn(line, "\n")] = '\0';
            execute_command(line, env, line_count);
        }
    }
    free(line);
    return (0);
}
