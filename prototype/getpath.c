#include "main.h"

/**
 * get_path - return a string to a path
 *
 * Return: pointer to the path variable
 */
char *get_path()
{
	char *tmp, *var;

	while (*environ != NULL)
	{
		tmp = strdup(*environ);
		if (tmp == NULL)
		{
			perror("error");
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
	else
	{
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
	}

	return (p);
}
/**
 * get_stat - check for the existance of given file
 * @f_name: file name
 *
 * Description: the function uses the system call stat to get the status of a
 * file/information, through struct stat structure.
 * Return: 0 on success, otherwise 1
 */
int get_stat(char *f_name, char *f_path)
{
	struct stat *file_info;

	if (stat(f_path, file_info) == 0)
	{
		printf(" FOUND:\t%s\n", f_name);
		printf("in path: %s\n", f_path);
		/* access file properties */
		printf("file user ID: %d\n", file_info->st_uid);
	}
	else
	{
		printf("Error- check_file\n");
		return (1);
	}

	return (0);
}
int get_file_stat(char *f)
{
	char *file, *path;
	int i, j, p_len;
	array_t *token;

	file = f;
	path = get_path();
	token = (array_t *)malloc(sizeof(array_t));
	token->arr = arr_tokens(path + 5, ":");
	token->size = token_size(path + 5, ":");
	//printf("%s\n", path + 5);
	free(path);

	for (i = 0; i < (token->size); i++)
	{
		p_len = strlen((token->arr)[i]) + strlen(file) + 1;
		(token->arr)[i] = get_fullpath((token->arr)[i], file, p_len);
		get_stat(file, (token->arr)[i]);
		printf("%s\n", (token->arr)[i]);
	}
	i--;
	for (; i >= 0; i--)
	{
		free((token->arr)[i]);
	}
	free(token->arr);
	free(token);

	return (0);
}
int main(int ac, char *av[])
{
	int i;

	for (i = 1; i < ac; i++)
	{
		get_file_stat(av[i]);
	}

	return (0);
}
