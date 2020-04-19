#include "shell.h"
/**
 *exit_cmd - function of exits to program
 *@array: array whit the command
 *@av: parameter of main
 *@line: getline buffer to frees
 *@cont: count of executes
 *@ret_status: last status to exit
 *Return:status
 */
int exit_cmd(char **array, char *av[], char *line, int cont, int ret_status)
{
	int i = 0, exit_stat, numb;

	while (array[i] != NULL)
	{
		i++;
	}
	if (i == 1)
	{
		free(array);
		free(line);
		exit(ret_status);
	}
	if (i >= 2)
	{
		for (i = 0; array[1][i] != '\0'; i++)
		{
			numb = _isdigit(array[1][i]);
			if (numb == 0)
			{
				print_errors(array, av, cont, 2);
				ret_status = 2;
				return (ret_status);
			}
		}
		exit_stat = _atoi(array[1]);
		free(array);
		free(line);
		exit(exit_stat);
	}
	return (ret_status);
}
