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

	(void) ac;
	input = NULL;
	if (fflush(NULL) != 0)
		perror("fflush(stdin)");
	printf("#cisfun$ ");
	while ((num_read = getline(&input, &n, stdin) != EOF))
	{
		if (cmd_found(&input, av))
			exec_cmd(input, envp);
		printf("#cisfun$ ");
	}
	putchar(10);
	free(input);

	return (0);
}
