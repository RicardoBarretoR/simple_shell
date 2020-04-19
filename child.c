#include "shell.h"
/**
 *child - creates the child process
 *@array: array of argument strings passed to the new program
 *Return: return the child's exit status.
 */
int child(char **array)
{
	int  valu_sta, status;
	const char * command;
	struct stat buf;
	pid_t child;

	if (array == NULL)
		return (EXIT_SUCCESS);

	command = array[0];

	if (stat(command, &buf) == -1)
		return (127);

	if (access(command, X_OK) == -1)
		return (126);

	child = fork();

	if (child == 0)
	{
		valu_sta = execve(command, array, environ);
	}
	else if (child > 0)
	{
		wait(&status);
		valu_sta = WEXITSTATUS(status);
	}
	return (valu_sta);
}
