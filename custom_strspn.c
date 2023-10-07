#include "shell.h"
/**
 * custom_strspn - checks length of substring
 * @str: string again
 * @findem: substring
 * Return: length of substring
 */
unsigned int custom_strspn(char *str, char *findem)
{
	unsigned int y, u, m = 0;

	for (y = 0; str[y] != '\0'; y++)
	{
		for (u = 0, m = 0; findem[u] != '\0'; u++)
		{
			if (str[y] == findem[u])
				m++;
		}
		if (m == 0)
			return (y);
	}
	return (y);
}
