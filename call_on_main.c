#include "shell.h"
/**
 * call_w_cmd - calls for execution using a single command
 * @k: cingle command
 * @paths: array of path environments
 * @envp: environment variable
 * @av: argument vector
 * @i: path index
 */
void call_w_cmd(char **k, char **paths, char **envp, char **av, int i)
{
	int f_exec; /* execution flag */
	char *cmd;

	cmd = *k;
	f_exec = 0;
	if ((check_access(cmd) == 0) && cmd_found(cmd, av) && i == -1)
	{
		f_exec = 1;
		exec_cmd(cmd, envp);
	}
	if (i && check_access(paths[i]) == 0)
	{
		exec_cmd(paths[i], envp);
		f_exec = 1;
	}
	else
		if (isatty(STDIN_FILENO) && !f_exec)
			perror(av[0]);
}
/**
 * call_w_args - calls for execution using command with multiple options
 * @cmd_args: array of command args
 * @paths: array of path environments
 * @envp: environment variable
 * @av: argument vector
 * @i: path index
 */
void call_w_args(char **cmd_args, char **paths, char **envp, char **av, int i)
{
	if (check_access(cmd_args[0]) == 0 && cmd_found(cmd_args[0],
							av) && i == -1)
		exec_cmd_args(cmd_args, envp);
	if (i && check_access(paths[i]) == 0)
	{
		free(cmd_args[0]);
		cmd_args[0] = _strdup(paths[i]);
		exec_cmd_args(cmd_args, envp);
	}
	else
		if (isatty(STDIN_FILENO))
			perror(av[0]);
}
