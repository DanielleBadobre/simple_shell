#include "unixshell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print - prints the character c to stdout
 * @str: The str to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int print(char *str)
{
	int count;

	count = 0;

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	str = '\0';

	return (count);
}
