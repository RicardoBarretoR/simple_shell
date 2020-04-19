#include "shell.h"
/**
 *child - creates the child process
 *@array: array of argument strings passed to the new program
 *@av: array arguments from main
 *@cont: count number of times that program is called
 *Return: return the child's exit status.
 */
int child(char **array, char *av[], int cont)
{
	int  valu_sta, status;
	struct stat buf;
	pid_t ch;

	if (array == NULL || array[0] == NULL)
		return (EXIT_SUCCESS);

	if (stat(array[0], &buf) == -1)
	{
		print_errors(array, av, cont, 127);
		return (127);
	}
	if (access(array[0], X_OK) == -1)
	{
		print_errors(array, av, cont, 126);
		return (126);
	}

	ch = fork();

	if (ch == 0)
	{
		valu_sta = execve(array[0], array, environ);
	}
	else
	{
		wait(&status);
		valu_sta = WEXITSTATUS(status);
	}
	return (valu_sta);
}
