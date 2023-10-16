#include "unixshell.h"

/**
 * msgerror - A function that prints message not found.
 *  @name: The name of the shell.
 *  @fact: Number of fact.
 *  @cmd_opt: The pointer to tokenized cmd_opt.
 * Return: Nothing.
 *
 **/
void msgerror(char *name, int fact, char **cmd_opt)
{
	char c;

	c = fact + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd_opt[0], _strlen(cmd_opt[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * print_env - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
