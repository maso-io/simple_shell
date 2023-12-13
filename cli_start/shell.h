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

#define MAX_SIZE 100
/**
 * ul_int - Unsigned long int type definition
 */
typedef unsigned long int ul_int;

/* check for command */
int cmd_found(char **cmd, char **av);
/* executes cmd given */
void exec_cmd(char *, char **);
#endif /* shell.h */
