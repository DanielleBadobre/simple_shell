#include "unixshell.h"

#include "unixshell.h"
int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

//while (TRUE)
//{
	printf("$ ");
	fflush(stdout);

	read = _getline(&line, &len);
	if (read != -1)
		printf("%s",line);
	else
		perror("getline");
//}
	free(line);
	return 0;
}
