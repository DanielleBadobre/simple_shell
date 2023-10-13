#include "unixshell.h"

/**
 *_strchr - Locates a character in a string.
 *@s: The string to be searched.
 *@c: The character to be located.
 *
 *Return: If c is found - a pointer to the first occurence.
 *If c is not found - NULL.
 */

char *_strchr(const char *s, char c)
{
	int index;


	for (index = 0; s[index] != '\0'; index++)
	{
		if (s[index] == c)
			return ((char *)(s + index));
	}

	return (NULL);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer of an array of chars
 */
char *_strdup(char *str)
{
	char *strout;
	unsigned int i, j;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	strout = (char *)malloc(sizeof(char) * (i + 1));

	if (strout == NULL)
		return (NULL);

	for (j = 0; j <= i; j++)
		strout[j] = str[j];

	return (strout);
}
