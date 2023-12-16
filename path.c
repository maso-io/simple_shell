#include "shell.h"
/**
 * get_path - get an array of path environment variable
 * @prog: name of the program to append to path environments
 *
 * Return: pointer to an array of paths
 */
char **get_path(char *prog)
{
	int i;
	char *path, **paths;

	while (*environ != NULL)
	{
		path = strdup(*environ);
		if (path == NULL)
		{
			printf("Erro: get_path\n");
			exit(96);
		}
		if (strncmp(path, "PATH=", 5) == 0)
			break;
		environ++;
		free(path);
	}
	i = token_size(path + 5, ":");
	paths = multi_tokens(path + 5, ":");
	free(path);
	for (; i >= 0; i--)
		paths[i] = append_prog(&paths[i], prog);

	return (paths);
}
/**
 * append_prog - appends name of given cmd/prog to path
 * @path: pointer to memory with path
 * @s: name of program
 *
 * Return: pointer to memory with program appended
 */
char *append_prog(char **path, char *s)
{
	int len, p_len;
	char *p;
	char c[] = "/";

	p = *path;
	if (p == NULL)
		return (NULL);
	p_len = strlen(p);
	len = strlen(p) + strlen(s) + 1;
	if (strlen(s) == 0)
		return (p);
	if (p[p_len - 1] != '/')
	{
		p = (char *)realloc(p, sizeof(char) * (len + 1));
		strcat(p, c);
		strcat(p, s);
	}
	else
	{
		p = (char *)realloc(p, sizeof(char) * len);
		strcat(p, s);
	}

	return (p);
}
/**
 * cmd_found_path - check if the program exists in the full path
 * @paths: array of full paths
 *
 * Return: index of when the program exists in path environment variable
 */
int cmd_found_path(char **paths)
{
	int i;
	struct stat file_info;

	for (i = 0; paths[i] != NULL; i++)
	{
		if (stat(paths[i], &file_info) == 0)
			return (i);
	}

	return (-1);
}
