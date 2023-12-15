#include "main.h"
#include "shell.h"
/**
 * _strdup - creates a duplicate memory space and copies string into it
 * @buffer: pointer to allocate memory to
 * @s: string to copy into the memory space
 * @len: lenght of the string
 */
void _strdup(char **buffer, const char *s, int len)
{
	int i;

	/* Allocate space for the string and the null terminator */
	*buffer = (char *)realloc(*buffer, sizeof(char) * len);
	if (*buffer == NULL)
	{
		printf("Error: memory allocation failed\n");
		exit(1);
	}
	for (i = 0; i < len - 1; i++)
	{
		/* Assign each character of s to the buffer */
		(*buffer)[i] = s[i];
	}
	/* Add the null terminator at the end */
	(*buffer)[i] = '\0';
}
/**
 * free_token - free memory allocated to a struct array_t
 * @t: pointer to memory allocated to a array_t
 */
void free_token(array_t *t)
{
	int i;

	i = t->size;
	for (; i >= 0; i--)
		free(t->arr[i]);
	free(t->arr);
	free(t);
}
/**
 * free_arr_token - free memory allocated to an array of words
 * @arr_t: pointer to memory with array of words
 * @d: delimeter
 */
void free_arr_token(char **arr_t, char *d)
{
	int i;

	i = (int) token_size(*arr_t, d);
	for (; i >= 0; i--)
	{
		free(arr_t[i]);
	}
	free(arr_t);
}
