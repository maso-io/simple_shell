#include "shell.h"

/**
 * main - main shell
 * @ac: argument count
 * @av: argument vector
 * @envp: environment variable
 *
 * Return: always 0.
 */
int main(int ac, char *av[], char *envp[])
{
	size_t n;
	ssize_t num_read;
	char *input;

	input = NULL;
	n = 0;
	printf("$ ");
	while ((num_read = getline(&input, &n, stdin) != EOF))
	{
		input = strndup(input, strlen(input) - 1);
		if (cmd_found(input))
			exec_cmd(input, envp);
		printf("$ ");
	}
	putchar(10);
	free(input);

	return (0);
}
