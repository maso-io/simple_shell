#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * main - implement stat in a main function
 *
 * Description: the function uses the system call stat to get the status of a
 * file/information, through struct stat structure.
 * Return: 0 on success, otherwise 1
 */
int main(int ac, char **argv, char **env)
{
	int i, flag;
	char *path;
	struct stat *file_info;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", argv[0]);
		return (1);
	}
	for (i = 1; i < ac; i++)
	{
		file = argv[i];
		flag = check_file(file, path, ":");
		if (flag == 0)
		{
			printf(" FOUND MAIN\n");
		}
		else
			printf("FILE %s NOT FOUND\n", file);
	}

	return (0);
}
