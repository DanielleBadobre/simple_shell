#include "unixshell.h"


int main(void)
{
	char str[] = "Christ is Lord";
	const char * delim = " ";
	char *token = NULL;
	char *saveptr;

	token = _strtok(str, delim, &saveptr);
	while(token != NULL)
	{
		printf("%s\n", token);
		token = _strtok(NULL, delim, &saveptr);
	}

	return 0;
}
