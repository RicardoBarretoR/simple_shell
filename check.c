#include "simple_shell.h"
/**
 * check - function to check some conditions of getline
 * @last_st: indicates last status of the program
 * @rline: string to free
 * Return: the buffer of getline function
 */
int check(int last_st, char *rline)
{
	int r;

	if (rline == NULL)
	{
		free(rline);
		return (1);
	}
	rline = replace_function(rline);   /*replacing /t b spaces*/
	r = check_getline(rline);  /*spaces and tab errors with enter*/
	if (r == 0)
	{
		free(rline);
		return (last_st);
	}
	rline = strtok(rline, "\n\t"); /*Cleaning the \n\t*/
	if (rline == NULL)
	{
		free(rline);
		return (2);
	}
	return (0);
}
