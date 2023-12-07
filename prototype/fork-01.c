/* ----------------------------------------------------------------- */
/* PROGRAM  fork-01.c                                                */
/*    This program illustrates the use of fork() and getpid() system */
/* calls.  Note that write() is used instead of printf() since the   */
/* latter is buffered while the former is not.                       */
/* ----------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUF_SIZE 100
#define MAX_COUNT 10

void ChildProcess(void); /* child process prototype */
void ParentProcess(void); /* parent process prototype */

int main(void)
{
	int status;	/* stores the exit status of a child process */
	pid_t pid, cpid;

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
		ChildProcess();
	else
	{
		cpid = waitpid(pid, &status, 0); /* wait for the child process to
											* finish and return
											* its processID
											*/
		printf("\tfinished child process: %d\n", cpid);
		if (WIFEXITED(status))
		{
			/* Child process terminated normally */
			printf("Child process exited with status: %d\n", WEXITSTATUS(status));
		}
		fflush(stdout); /* flush the stdout buffer */
		ParentProcess(); /* start the parent process */
	}

	return (0);
}

void ChildProcess(void)
{
	int pid, i;
	char buf[BUF_SIZE];

	pid = getpid();
	for (i = 1; i <= MAX_COUNT / 2; i++)
	{
		sprintf(buf, "This line is from child process, pid %d, value = %d\n", pid, i);
		write(1, buf, strlen(buf));
	}
	printf("\t*** Child process is done ***\n");
	exit(1);
}
void ParentProcess()
{
	int pid, i;
	char buf[BUF_SIZE];

	pid = getpid();
	for (i = MAX_COUNT / 2 + 1; i <= MAX_COUNT; i++)
	{
		sprintf(buf, "This line is from parent process, pid %d, value = %d\n", pid, i);
		write(1, buf, strlen(buf));
	}
	printf("\t*** Parent is done ***\n");
}
