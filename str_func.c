#include "unixshell.h"

/**
 ** _strchr - a function to find the first occurrence of a substring within a given string.
 ** @s: given string
 ** @c: substring
 ** Return: Pointer to the first occurence of @c in @s
 **/
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return ('\0');
}
