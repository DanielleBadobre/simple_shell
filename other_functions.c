#include "unixshell.h"

/**
 * msgerror - A function that prints message not found.
 *  @name: The name of the shell.
 *  @value: Number of time program runs.
 *  @cmd_opt: The pointer to tokenized cmd_opt.
 * Return: Nothing.
 *
 **/

void msgerror(char *name, int value, char **cmd_opt)
{

	char c;

	c = value + '0';
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

/**
 * _atoi - converts a string to an integer
 * @s: input string
 * Return: integer
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;
		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}

/**
 * change_dir - function that changes working directory.
 * @path_name: new current working directory.
 * Return: 0 on success, -1 on failure.
 */
int change_dir(const char *path_name)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path_name == NULL)
		path_name = getcwd(buf, size);
	if (chdir(path_name) == -1)
	{
		perror(path_name);
		return (98);
	}
	return (1);
}

/**
 * signal_input - function to handle signals e.g Ctr + C signal.
 * @signal: signal to handle.
 */
void signal_input(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 4);
}

