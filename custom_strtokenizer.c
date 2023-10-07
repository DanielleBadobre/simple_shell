#include "shell.h"
/**
 * custom_strtokenizer - gets token from pointer
 * @str: string
 * @delim: the characters delimiting
 * @ptr_saved: previously saved pointer
 * Return: pointer to token
 */
char *custom_strtokenizer(char *str, char *delim, char **ptr_saved)
{
	unsigned int i;
	char *end;

	if (str == NULL)
		str = *ptr_saved;
	if (*str == '\0')
	{
		*ptr_saved = str;
		return (NULL);
	}
	i = custom_strspn(str, delim);
	if (i > 0)
		str = str + i;
	if (*str == '\0')
	{
		*ptr_saved = str;
		return (NULL);
	}
	i = custom_strcspan(str, delim);
	if (i > 0)
		end = str + i;
	if (*end == '\0')
	{
		*ptr_saved = end;
		return (str);
	}
	*end = '\0';
	*ptr_saved = end + 1;
	return (str);
}
