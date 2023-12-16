#include "shell.h"
/**
 * _strdup - duplicate string s
 * @s: string to duplicate
 *
 * Return: memory with the duplicated string
 */
char *_strdup(char *s)
{
	int len;
	char *mem;
	int i = 0;

	len = _strlen(s) + 1;
	mem = (char *)malloc(sizeof(char) * len);
	if (mem == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mem[i] = s[i];
		i++;
	}
	/*if (mem[i - 1] != '\0' && s[i] == '\0')*/
	mem[i] = '\0';

	return (mem);
}
/**
 * _strlen - calculate thre length of a string
 * @s: string
 *
 * Return: the length of a string, or -1
 */
int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
		i++;

	return (i);
}
/**
 * free_multi_token - free memory allocated to an array of words
 * @arr_t: pointer to memory with array of words
 * @d: delimeter
 */
void free_multi_token(char **arr_t, char *d)
{
	int i;

	i = (int) token_size(*arr_t, d);
	for (; i >= 0; i--)
	{
		free(arr_t[i]);
	}
	free(arr_t);
}
/**
 * free_multi_path - free memory allocated to an array of paths
 * @arr_p: pointer to memory with array of paths
 */
void free_multi_path(char **arr_p)
{
	int i;

	i = 0;
	for (; arr_p[i] != NULL; i++)
	{
		free(arr_p[i]);
	}
	free(arr_p);
}
