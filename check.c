#include "simple_shell.h"
/**
 * check - function to check some conditions of getline
 * @num: indicates interactive or non-interactive mode
 * @last_st: indicates last status of the program
 * Return: the buffer of getline function
 */
char *check(int num, int last_st)
{
	char *rline = NULL;
	int r;

	signal(SIGINT, manage_signal);
	if (num != 0)
		prompt(); /*print prompt*/
	rline = _getline(stdin, num);
	if (rline == NULL)
	{
		free(rline);
		exit(1);
	}
	rline = replace_function(rline);   /*replacing /t b spaces*/
	r = check_getline(rline);  /*spaces and tab errors with enter*/
	if (r == 0)
	{
		free(rline);
		exit(last_st);
	}
	rline = strtok(rline, "\n\t"); /*Cleaning the \n\t*/
	if (rline == NULL)
	{
		free(rline);
		exit(2);
	}
	return (rline);
}
