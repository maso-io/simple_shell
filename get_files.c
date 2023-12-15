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
	{
		perror("access");
		return (-1);
	}

	return (0);
}
/**
 * single_token - get one token(word/cmd) from input token
 * @s: pointer to memory with the user input
 *
 * Return: pointer to memory with the token/cmd
 */
char *single_token(char **s)
{
	char *str;
	char d[] = " \t\n";

	str = strtok(*s, d);
	if (str != NULL)
		return (str);
	return (NULL);
}
/**
 * token_size -  returns the number of tokens the string will produce
 * @s: string to tokenize
 * @d: delimeter to use on string
 *
 * Return: number of tokens that would be produced
 */
size_t token_size(char *s, char *d)
{
	char *tmp;
	size_t size;

	if (s == NULL)
		return (0);
	size = 0;
	tmp = strdup(s);
	if (strtok(tmp, d) != NULL)
		size++;
	while (strtok(NULL, d) != NULL)
		size++;
	free(tmp);
	tmp = NULL;

	return (size);
}
