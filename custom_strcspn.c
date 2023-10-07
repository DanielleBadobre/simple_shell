#include "shell.h"
/**
 * custom_strcspn - checks number of chars before char to compare
 * @str: well, the string
 * @notyet: chars to check
 * Return: number of characters
 */
unsigned int custom_strcspn(char *str, char *notyet)
{
	unsigned int m, n = 0;

	for (m = 0; str[m] != '\0'; m++)
		for (n = 0; notyet[n] != '\0'; n++)
			if (str[m] == notyet[n])
				return (m);
	return (m);
}
