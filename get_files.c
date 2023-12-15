#include "shell.h"
/**
 * cmd_found - check if command (cmd) exists in pwd
 * @cmd: command
 * @av: argument vector
 *
 * Return: 1 is cmd exists, otherwise 0
 */
int cmd_found(char *cmd, char **av)
{
	struct stat file_info;

	if (stat(cmd, &file_info) == 0)
		return (1);
	perror(av[0]);

	return (0);
}
/**
 * check_access - check for permission to access the file
 * @path: path to file/program
 *
 * Return: 0 on sucess , otherwise -1
 */
int check_access(char *path)
{
	if (access(path, F_OK | X_OK) != 0)
		return (-1);

	return (0);
}

