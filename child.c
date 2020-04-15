#include "simple_shell.h"
/**
 * child - creates the child process
 * @path: correct path to be executed
 * @array: array of arguments
 * @rline: line readed from stdin
 * Return: Nothing
 */
int child(char *path, char **array, char *rline)
{
	int status, exe, ch, val, exit_stat;
	pid_t wt;

	ch = fork();
	if (ch == 0)
	{
		exe = execve(path, array, NULL);
		if (exe == -1)
		{
			free_arraybid(array);
			free(rline);
			perror("Error with execve");
			/*add free dirs too*/
			return (-1);
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
		val = WIFEXITED(status);
		if (val)
		{
			exit_stat = WEXITSTATUS(status);
			return (exit_stat);
		}
	}
	else
	{
		perror("Error with fork");
		exit(1);
	}
	return (0);
}
