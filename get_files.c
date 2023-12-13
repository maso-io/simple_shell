#include "shell.h"
/**
 * cmd_found - check if command (cmd) exists in pwd
 * @cmd: command
 *
 * Return: 1 is cmd exists, otherwise 0
 */
int cmd_found(char *cmd)
{
	struct stat file_info;

	if (stat(cmd, &file_info) == 0)
		return (1);
	else
		perror("error");

	return (0);
}
