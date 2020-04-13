#include "simple_shell.h"
/**
 * exit_cmd - exits from the program
 * @array: array whit the command
 * Return: Nothing
 */
void exit_cmd(char **array, char *rline)
{
	int i = 0;
	int ex_value;

	free(rline);
	while (array[i] != NULL)
	{
		i++;
	}
	if (i == 2)
	{
		ex_value = atoi(array[1]);
		free_arraybid(array);
		exit(ex_value);
	}
	else if (i == 1)
	{
		free_arraybid(array);
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("Exit, to many arguments");
	}
}
