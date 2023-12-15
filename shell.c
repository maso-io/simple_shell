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
	int init;
	size_t n;
	ssize_t num_read;
	char *input, *cmd;

	(void) ac;
	init = 0;
	input = NULL;
	do {
		if (init)
		{
			cmd = _strdup(input);
			if (cmd_found(cmd, av) && (check_access(cmd) == 0))
				exec_cmd(cmd, envp);
			free(cmd);
		}
		init = 1;
		if (isatty(STDIN_FILENO))
			printf("$ ");
	} while ((num_read = getline(&input, &n, stdin) != EOF));
	if (isatty(STDIN_FILENO))
		putchar(10);
	free(input);

	return (0);
}

