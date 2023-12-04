#include "shell.h"
/**
* _getline - gets input from the user
* @buffer: buffer for user input
*
* Return: Number of characters printed or EOF on error
*/
int _getline(char **buffer);

/**
 * main - creates a simple shell
 *
 * Return: always 0.
 */
int main()
{
	char *buffer, **arr;

	buffer = (char *)malloc(100);
	if (!buffer)
		return (-1);
	/* 1. get the line */
	printf("$ ");
	while(_getline(&buffer) != EOF)
	{
		//arr = split(&lineptr);
		printf("---- TEST: BUFFER --> %s <----\n", *buffer);
		printf("$ ");
	}
	putchar(10);
	/* 2. chop it up to pieces  so to have the different args */

	/* 3. create a child process to execute of it */

	/* execute */

	return (0);
}
int _getline(char **buffer)
{
	int len;
	size_t n;
	char *str, *lineptr = NULL;

	n = 0;
	if (getline(&lineptr, &n, stdin) == EOF)
	{
		free(lineptr);
		return (EOF);
	}
	len = strlen(lineptr);
	buffer = (char *)realloc(sizeof(char) * strlen(buffer));
	*buffer = strdup(lineptr);
	*buffer[len - 1] = '\0';

	printf("%s\n", *buffer);

	return (len - 1);
}
