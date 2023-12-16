#include "shell.h"

/**
 * main - main shell
 * @ac: argument count
 * @av: argument vector
 * @envp: environment variable
 *
 * Return: always 0.
 */
int main(int __attribute__((unused)) ac, char *av[], char *envp[])
{
	int init, i;
	size_t n, size, num_read;
	char *input, *cmd, **cmd_args, **paths;

	init = 0, input = NULL;
	do {
		if (init)
		{
			size = token_size(input, " \t\n");
			if (size == 1)
			{
				(void) cmd_args;
				cmd = single_token(&input);
				cmd = _strdup(cmd);
				paths = get_path(cmd);
				i = cmd_found_path(paths);
				call_w_cmd(&cmd, paths, envp, av, i);
			}
			else
			{
				(void) cmd;
				cmd_args = multi_tokens(input, " \t\n");
				paths = get_path(cmd_args[0]);
				i = cmd_found_path(paths);
				call_w_args(cmd_args, paths, envp, av, i);
			}
			if (size == 1)
				free(cmd);
			else
				free_multi_token(cmd_args, " \t\n");
			free_multi_path(paths);
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
