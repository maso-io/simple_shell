#include "shell.h"
/**
 * exec_cmd - executes the given command
 * @cmd: command to execute
 * @env: environment variable
 */
void exec_cmd(char *cmd, char **env)
{
	pid_t cpid, w;
	int wstatus;
	char *args[2];

	args[0] = cmd;
	args[1] = NULL;
	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0)
	{
		/* Code executed by child */
		if (execve(args[0], args, env) != 0)
			perror("error");
	}
	else
	{                    /* Code executed by parent */
		do {
			w = waitpid(cpid, &wstatus, 0);
			if (w == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			if (WIFEXITED(wstatus))
			{
				continue;
				/*printf("exited, status=%d\n", WEXITSTATUS(wstatus));*/
			}
			else if (WIFSIGNALED(wstatus))
			{
				printf("killed by signal %d\n", WTERMSIG(wstatus));
			}
		} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
		/*exit(EXIT_SUCCESS);*/
	}
}
