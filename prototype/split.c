#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* splits a sentence to an array of words */
char **arr_word(char *s);
/**
 * main - splits a string and returns an array of each word in the string
 *
 * Return: always 0.
 */
int main(void)
{
	int i;
	char **words, *tmp;

	i = 0;
	words = arr_word("Test string !");
	while (i < 3)
	{
		printf("%s\n", words[i]);
		tmp = words[i];
		free(tmp);
		i++;
	}
	free(words);

	return (0);
}
/**
 * arr_word - takes a string and convert it to an array of words
 * @s: string with words
 *
 * Return: pointer to an arrau of words or null
 */
char **arr_word(char *s)
{
	int flag, word_c;
	char **buffer, *word, *sentence;

	char d[2] = {' ', '\0'};
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
	free(sentence);

	return (buffer);
}
