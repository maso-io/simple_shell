#include "shell.h"
#include "main.h"
/**
 * get_cmd_stat - checks if the command exists in current dir
 * @cmd: the command to check for
 * @envp: enviroment variable
 *
 * Return: returns 0 if the cmd 'exists', otherwise 2
 */
int get_cmd_stat(char **cmd, char **envp)
{
	struct stat info_file;

	(void) envp;

	if (stat(cmd[0], &info_file) == 0)
	{
		/*execve(cmd[0], cmd, envp);*/
	}
	else
	{
		return (2);
	}

	return (0);
}
/**
 * check_fgets - checks for piped input
 * @cmd: memory to place holder for cmd
 */
int check_fgets(char **cmd)
{
	char input[MAX_SIZE];

	fgets(input, MAX_SIZE, stdin);
	if (input == NULL)
	{
		return (-1);
	}
	_strdup(cmd, input, strlen(input));

	return (0);
}
