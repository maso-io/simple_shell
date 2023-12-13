#include "main.h"

/**
 * get_path - return a string to a path
 *
 * Return: pointer to the path variable
 */
char *get_path()
{
	char *tmp;

	while (*environ != NULL)
	{
		tmp = strdup(*environ);
		if (tmp == NULL)
		{
			printf("error -strdup\n");
			exit(96);
		}
		if (strncmp(tmp, "PATH=", 5) == 0)
		{
			break;
		}
		environ++;
		free(tmp);
	}
	return (tmp);
}
/**
 * get_fullpath - get's path with the name appended
 * @p: pointer to the memory with the path
 * @file_name: file name to append to the path
 * @len: full path length
 *
 * Return: string pointer to full path
 */
char *get_fullpath(char *p, char *file_name, int len)
{
	int fn_len, p_len;
	char c[] = "/";

	p_len = strlen(p);
	fn_len = strlen(file_name);
	if (fn_len == 0)
		return (p);
	if (p[p_len - 1] != '/')
	{
		p = (char *)realloc(p, sizeof(char) * (len + 1));
		strcat(p, c);
		strcat(p, file_name);
	}
	else
	{
		p = (char *)realloc(p, sizeof(char) * len);
		strcat(p, file_name);
	}

	return (p);
}
/**
 * get_stat - check for the existance of given FILE in $PATH
 * @f_name: file name
 * @f_path: file name appended to the full path to an env variable
 * @last_path: flag for if you on the last environment variable
 *
 * Description: the function uses the system call stat to get the status of a
 * file/information, through struct stat structure.
 * Return: 0 on success, otherwise 1
 */
int get_stat(char *f_name, char *f_path, int last_path)
{
	struct stat file_info;

	(void) f_name;
	(void) last_path;
	if (stat(f_path, &file_info) == 0)
	{
		/*printf(" FOUND:\t%s\n", f_name);*/
		/*printf("in path: %s\n", f_path);*/
		/* access file properties */
		/*printf("file user ID: %d\n", file_info.st_uid);*/
	}
	else
	{
		return (1);
	}


	return (0);
}
/**
 * get_file_stat - checks if the given command is in env variables
 * @k: pointer to the command
 *
 * Return: 0 if the file is found, otherwise 3
 */
int get_file_stat(char **k)
{
	char *cmd, *path;
	int i, p_len, flag;
	array_t *token;

	flag = 1;
	cmd = *k;
	path = get_path();
	token = (array_t *)malloc(sizeof(array_t));
	token->arr = arr_tokens(path + 5, ":");
	token->size = token_size(path + 5, ":");
	free(path);

	for (i = 0; i < (token->size); i++)
	{
		p_len = strlen((token->arr)[i]) + strlen(cmd) + 1;
		(token->arr)[i] = get_fullpath((token->arr)[i], cmd, p_len);
		if (i == (token->size) - 1)
			flag = get_stat(cmd, (token->arr)[i], 1);
		else
			flag = get_stat(cmd, (token->arr)[i], 0);
		/*
		 *if (flag == 1 && i == token->size - 1)
		 *{
		 *	/cmd is not in PATH /
		 *	free_token(token);
		 *	return (3);
		 *}
		 */
		if (flag == 0)
		{
			*k = strdup(token->arr[i]);
			free_token(token);
			return (0);
		}
	}
	free_token(token);

	return (3);
}
f1 2015 melbourne highlights
