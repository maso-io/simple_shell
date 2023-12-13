#include "shell.h"
/**
 * cmd_found - check if command (cmd) exists in pwd
 * @cmd: command
 * @av: argument vector
 *
 * Return: 1 is cmd exists, otherwise 0
 */
int cmd_found(char **cmd, char **av)
{
	struct stat file_info;

	*cmd = strndup(*cmd, strlen(*cmd) - 1);
	if (stat(*cmd, &file_info) == 0)
		return (1);
	perror(av[0]);

	return (0);
}
