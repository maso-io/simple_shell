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

	len = _strlen(s);
	mem = (char *)malloc(sizeof(char) * len);
	if (mem == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mem[i] = s[i];
		i++;
	}
	if (mem[i - 1] != '\0' && s[i] == '\0')
		mem[i - 1] = '\0';

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
	while (*s != '\0')
	{
		i++;
		s++;
	}

	return (i);
}
