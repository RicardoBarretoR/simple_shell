#include "simple_shell.h"
/**
 * child - creates the child process
 * @array: array of arguments
 * @rline: line readed from stdin
 * Return: Nothing
 */
void child(char **array, char *rline)
{
	int status, exe, ch;
	pid_t wt;

	ch = fork();
	if (ch == 0)
	{
		printf("exe %s\n", array[0]);
		exe = execve(array[0], array, NULL);
		if (exe == -1)
		{
			free_arraybid(array);
			free(rline);
			perror("Error with execve");
			/*add free dirs too*/
			exit(1);
		}
	}
	else if (ch > 0)
	{
		wt = waitpid(-1, &status, 0);
		if (wt < 0)
		{
			perror("Error with wait");
			exit(1);
		}
	}
	else
	{
		perror("Error with fork");
		exit(1);
	}
}
