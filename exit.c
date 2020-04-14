#include "simple_shell.h"
/**
 * exit_cmd - exits from the program
 * @array: array whit the command
 * Return: Nothing
 */
void exit_cmd(char **array, char *rline, int last_st)
{
	int i = 0;
	int ex_value;

	/*printf("exit last_st %d\n", last_st);*/
	free(rline);
	while (array[i] != NULL)
	{
		i++;
	}
	if (i == 2)
	{
		ex_value = _atoi(array[1]);
		free_arraybid(array);
		exit(ex_value);
	}
	else if (i == 1)
	{
		free_arraybid(array);
		exit(last_st);
	}
	else
	{
		perror("Exit, to many arguments");
	}
}
