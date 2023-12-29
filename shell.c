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
	size_t n, size, num_read, init = 0;
	char *input, *cmd, **cmd_args, **paths;

	input = NULL;
	do {
		if (init++)
		{
			size = token_size(input, " \t\n");
			if (size == 1)
			{
				(void) cmd_args;
				cmd = single_token(input);
				if ((cmd_found(cmd, av) == 1) && (check_access(cmd) == 0))
					exec_cmd(cmd, envp);
				else
				{
					paths = get_path(cmd);
					call_w_cmd(&cmd, paths, envp, av, cmd_found_path(paths));
					free_multi_path(paths);
				}
				free(cmd);
			}
			else
			{
				(void) cmd;
				cmd_args = multi_tokens(input, " \t\n");
				paths = get_path(cmd_args[0]);
				call_w_args(cmd_args, paths, envp, av, cmd_found_path(paths));
				free_multi_path(paths);
				free_multi_token(cmd_args, " \t\n");
			}
		}
		if (isatty(STDIN_FILENO))
			printf("$ ");
	} while ((num_read = getline(&input, &n, stdin) != EOF));
	if (isatty(STDIN_FILENO))
		putchar(10);
	free(input);
	return (0);
}
