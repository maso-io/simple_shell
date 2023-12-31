#ifndef SHELL
#define SHELL

#include <stddef.h> /* standard definitions */
#include <stdio.h> /* EOF macro */
#include <stdlib.h>/* import exit */
#include <unistd.h>/* import system calls */
#include <sys/wait.h>/* import wait , waitpid  wait fam of functions */
#include <sys/types.h>/* import pid_t, size_t, ssize_t those types  */
#include <string.h> /* import string utilities */
#include <sys/stat.h> /* import struct stat utilities */
#include <errno.h> /* import error codes */
#define MAX_SIZE 100
/* imports the environment variable */
extern char **environ;
/**
 * ul_int - Unsigned long int type definition
 */
typedef unsigned long int ul_int;


/* check for file in path */
int check_paths(char *file, char **path);
/* check for command */
int cmd_found(char *cmd, char **av);
/* executes cmd given */
void exec_cmd(char *, char **);
/* executes cmd given with options */
void exec_cmd_args(char **cmd, char **env);
/* check for file access permission */
int check_access(char *path);
/* gets a single command from user input */
char *single_token(char *s);
/* generate an array of arguments */
char **multi_tokens(char *, char *);
/* get an array of path environment variable with program appended */
char **get_path(char *);
/* appends name of program to path */
char *append_prog(char **, char *);
/* returns the integer index for the path environment where program is found */
int cmd_found_path(char **);

		/* UTILITIES */
/* duplicates the string s to memory */
char *_strdup(char *s);
/* calculates the length of string s */
int _strlen(char *s);
/* gets the number to delimeter separated arguments */
size_t token_size(char *s, char *d);
/* free input token */
void free_input(char **input);
/* free mutli input token */
void free_multi_token(char **arr_t, char *d);
/* free multi path token */
void free_multi_path(char **arr_p);
		/* MAIN CALLS */
/* main call on single argument */
void call_w_cmd(char **k, char **paths, char **envp, char **av, int i);
/* main call on multiple args */
void call_w_args(char **cmd_args, char **paths, char **envp, char **av, int i);
/* validate if the user gave input */
int validate_input(char *input);
#endif /* shell.h */
