#include "unixshell.h"

char *custom_strtok(char *str, const char *delim, char **saveptr)
{
    if (str != NULL)
        *saveptr = str;

    else if (*saveptr == NULL || **saveptr == '\0')
        return NULL; /* No more tokens to tokenize */

    /* Find the start of the token */
    char *token_start = *saveptr;
    while (*token_start != '\0' && strchr(delim, *token_start) != NULL)
    {
        token_start++;
    }

    if (*token_start == '\0')
    {
        *saveptr = NULL; /* There is no more tokens to tokenize */
        return NULL;
    }

    /* Find the end of the token*/
    char *token_end = token_start;
    while (*token_end != '\0' && strchr(delim, *token_end) == NULL)
    {
        token_end++;
    }

    /* Null-terminate the token and update saveptr */
    if (*token_end != '\0')
    {
        *token_end = '\0';
        *saveptr = token_end + 1;
    }
    else
    {
        *saveptr = NULL;
    }

    return token_start;
}


int main(void)
{
    char input[] = "Hello, world! This is a test.";
    char *token;
    char *saveptr;

    token = custom_strtok(input, " ,!.", &saveptr);
    while (token != NULL)
    {
        printf("%s\n", token);
        token = custom_strtok(NULL, " ,!.", &saveptr);
    }

    return 0;
}

