#include "shell.h"
#include "main.h"

/**
 * check_file - check for the existence of FILE in DELIMETER separated PATH
 * @file: file name
 * @path: path environment variable
 * @d: delimeter
 *
 * Description: the function uses the system call stat to get the status of a
 * file/information, through struct stat structure.
 * Return: 0 on success, otherwise 1
 */
int check_file(char *file, char *path, char *d)
{
	int i, path_s;
	char *f_name;
	struct stat file_info;
	array_t *token;

	token = (array_t *)malloc(sizeof(array_t));
	if (!token)
	{
		perror("error");
		exit(97);
	}
	token->arr = arr_tokens(path, d);
	token->size = token_size(path, d);
	for (i = 0; i < (token->size); i++)
	{
		path_s = strlen(file) + strlen((token->arr)[i]);
		f_name = malloc(sizeof(char) * path_s);
		if (f_name == NULL)
		{
			perror("error");
			exit(97);
		}
		strcat(f_name, (token->arr)[i]);
		strcat(f_name, file);
		if (stat(f_name, &file_info) == 0)
		{
			printf(" FOUND:\t%s\n", file);
			printf("in path: %s\n", f_name);
			/* access file properties */
			printf("file user ID: %d\n", file_info.st_uid);
		}
		else
		{
			printf("Error- check_file\n");
			return (1);
		}
	}
	free(f_name);
	for (i = (token->size) - 1; i >= 0; i--)
	{
		printf("free: %d\n", i);
		free((token->arr)[i]);
	}
	free(token);

	return (0);
}
/**
 * arr_tokens - takes a string and convert it to an array of words
 * @s: string with words to turn to tokens
 * @d: delimeter to use on the string
 *
 * Return: pointer to an array of NULL terminated tokens or NULL
 */
char **arr_tokens(char *s, char *d)
{
	int flag, word_c;
	char **buffer, *word, *sentence;

	flag = 1;
	word_c = 1;
	sentence = strdup(s);
	buffer = (char **)malloc(sizeof(char *) * word_c);
	if (!buffer)
		return (NULL);
	do {
		if (flag)
		{
			word = strtok(sentence, d);
			if (!word)
				return (NULL);
			buffer[0] = strdup(word);
			flag = 0;
			continue;
		}
		else
		{
			word = strtok(NULL, d);
			if (!word)
				break;
		}
		word_c++;
		buffer = realloc(buffer, sizeof(char *) * word_c);
		buffer[word_c - 1] = strdup(word);
		if (!buffer[word_c - 1])
			return (NULL);
	} while (1);
	buffer = realloc(buffer, sizeof(char *) * (word_c + 1));
	buffer[word_c] = NULL;
	free(sentence);

	return (buffer);
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

