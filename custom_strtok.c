#include "shell.h"
/**
 * custom_strtok - gets token from string
 * @str: string
 * @delim: delimiter chars
 * Return: pointer to extracted token
 */
char *custom_strtokr(char *str, char *delim)
{
	static char *ptr_saved;

	return (custom_strtok(str, delim, &ptr_saved));
}
