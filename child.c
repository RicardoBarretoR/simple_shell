#include "simple_shell.h"
/**
 * child - creates the child process
 * @path: correct path to be executed
 * @array: array of arguments
 * @rline: line readed from stdin
 * @cont: count the number of cycles
 * @av: arguments form main
 * Return: Nothing
 */
int child(char *path, char **array, char *rline, int cont, char *av[])
{
	int status, exe, ch, val, exit_stat;
	pid_t wt;

	ch = fork();
	if (ch == 0)
	{
		exe = execve(path, array, environ);
		if (exe == -1)
		{
			free_arraybid(array);
			_which_errors(av, cont, array, rline);
			free(rline);
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
