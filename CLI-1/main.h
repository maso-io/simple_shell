#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

extern char **environ;
/* check for file in path */
int check_paths(char *file, char **path);

/**
 * struct tokenized_array - contains pointer to an array and its size
 * @size: size of the array
 * @arr: pointer to memory allocated for the array
 */
struct tokenized_array
{
	int size;
	char **arr;
};
/**
 * array - type definition for struct d_array
 */
typedef struct tokenized_array array_t;

/* get_path - return a string to a path */
char *get_path();
/* check_file - check for the existence of FILE in DELIMETER separated PATH*/
int check_file(char *file, char *path, char *d);
/* arr_tokes - takes a string and convert it to an array of words */
char **arr_tokens(char *s, char *d);
/* token_size -  returns the number of tokens the string will produce */
size_t token_size(char *s, char *d);
/* get_file_stat - check if the file is in the path environments */
int get_file_stat(char **f);
/* get_stat - checks for stat of a file with path env appended */
int get_stat(char *f_name, char *f_path, int last_path);
/* get_fullpath - appends file name to path environment variables */
char *get_fullpath(char *p, char *file_name, int len);
/* get_path - returns PATH ENVIRONMENT VARIABLE */
char *get_path();
/* duplicates the string supplied by s */
void _strdup(char **buffer, const char *s, int len);
/* checks for the cmd in the current directory */
int get_cmd_stat(char **cmd, char **envp);
/* execute execve cmd with extra cmd args */
void call_cmd(char **args, char **env, char **buffer, char **cmd);
/* free memory allocated to a array_t */
void free_token(array_t *t);
/* gets command from the user */
int _getline(char **buffer);
/* reallocates memory pointed to by buffer to strdup(s) of size len */
void _strdup(char **buffer, const char *s, int len);
/* executes a full path command */
void callexe(char **args, char **env, char **buffer);
/* check for piped command */
int check_fgets(char **cmd);
#endif
