#include "main.h"
#include "shell.h"
/**
 * main - creates a simple shell
 * @ac: argument count
 * @argv: argument vector
 * @env: enviroment variable
 *
 * Return: always 0.
 */
int main(int ac, char *argv[], char *env[])
{
	int flag, flag_, i;
	char **args, *buffer;

	(void)ac;
	(void)argv;
	args = (char **)malloc(sizeof(char *) * 2);
	buffer = (char *)malloc(1);
	if (!buffer || !args)
		return (-1);
	/* 1. get the line */
	printf("#cisfun$ ");
	while (_getline(&buffer) != EOF)
	{
		/*args = arr_tokens(buffer, " ");*/
		args[0] = buffer;
		flag_ = get_cmd_stat(args, env);
		if (flag_ == 2)
			flag = get_file_stat(&args[0]);
		else
			flag = 1;
		if (flag == 0 && flag_ == 2)
			callexe(args, env, &buffer);
		if (flag_ == 0)
		{
			args[0] = buffer;
			callexe(args, env, &buffer);
		}
		if (flag == 3)
			printf("No such file or directory\n");
		printf("#cisfun$ ");
	}
	putchar(10);
	i = (int) token_size(buffer, " ");
	for (; i >= 0; i--)
	{
		free(args[i]);
	}
	free(args);
	free(buffer);

	return (0);
}
/**
 * _getline - gets input from the user
 * @buffer: buffer for user input
 *
 * Return: Number of characters printed or EOF on error
 */
int _getline(char **buffer)
{
	int len;
	size_t n;
	char *lineptr = NULL;

	n = 0;
	if (getline(&lineptr, &n, stdin) == EOF)
	{
		free(lineptr);
		return (EOF);
	}
	len = strlen(lineptr);
	_strdup(buffer, lineptr, len);

	free(lineptr);
	return (len - 1);
}
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
 * callexe - executes a program
 * @args: array of string arguments
 * @env: environment variable
 * @buffer: pointer to memory with user cmd
 */
void callexe(char **args, char **env, char **buffer)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Error");
			/*return;*/
			free(args[0]);
			free(args);
			free(buffer);
			exit(98);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 98)
			{
				/* Child process terminated ab-ormally */
				printf("c_process error, status: %d\n", WEXITSTATUS(status));
				return;
			}
			/*exit(98);*/
		}
	}
}
/**
 * call_cmd - executes a command with command line arguments
 * @args: array vector with with command full path
 * @env: enviroment variable
 * @buffer: pointer to user command
 * @cmd: array vector with full command arguments
 */
void call_cmd(char **args, char **env, char **buffer, char **cmd)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], cmd, env) == -1)
		{
			perror("Error");
			/*return;*/
			free(args[0]);
			free(args);
			free(buffer);
			exit(98);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 98)
			{
				/* Child process terminated ab-ormally */
				printf("c_process error, status: %d\n", WEXITSTATUS(status));
				return;
			}
			/*exit(98);*/
		}
	}
}
