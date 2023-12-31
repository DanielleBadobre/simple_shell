#include "unixshell.h"

/**
 * _strtok- a function to tokenize a string into smaller substrings
 * @str: the string to be parsed
 *@delim: apointert to NULL terminated characters to split delimiting character
 *@saveptr: a pointer to a char * variable that is used in order to
 * maintain context between successive calls that parse the same string
 *
 * Return: A pointer to nexte element
 *
 **/
char *_strtok(char *str, const char *delim, char **saveptr)
{
	char *token_start;
	char *token_end;

	if (str != NULL)
		*saveptr = str;

	else if (*saveptr == NULL || **saveptr == '\0')
		return (NULL); /* No more tokens to tokenize */

	/* Find the start of the token */
	token_start = *saveptr;

	while (*token_start != '\0' && _strchr(delim, *token_start) != NULL)
		token_start++;

	if (*token_start == '\0')
	{
		*saveptr = NULL; /* There is no more tokens to tokenize */
		return (NULL);
	}

	/* Find the end of the token*/
	token_end = token_start;

	while (*token_end != '\0' && _strchr(delim, *token_end) == NULL)
		token_end++;

	/* Null-terminate the token and update saveptr */
	if (*token_end != '\0')
	{
		*token_end = '\0';
		*saveptr = token_end + 1;
	}
	else
		*saveptr = NULL;

	return (token_start);
}
