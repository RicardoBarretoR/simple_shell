#include "simple_shell.h"
/**
 * hsh_loop - main code of the program
 * @num: indicates interactive or non-interactive mode
 * @cont: indicates that the prompt is show
 * @av: array of argumetns from main function
 * @last_st: indicates the last status
 * Return: status of the alst process
 */
int hsh_loop(int num, int cont, char *av[], int last_st)
{
	char *rline = NULL, *path, **array;
	int flag, get_error, er;

	signal(SIGINT, manage_signal);
	if (num != 0)
		prompt(); /*print prompt*/
	rline = _getline(stdin, num);
	if (rline == NULL)
		return (1);
	get_error = check(last_st, rline);
	if (get_error != 0)
		return (get_error);
	/*Cleaning the buffer*/
	array = sp_string(rline, " ");
	er = cases_command(av, cont, array, rline);
	if (er != 0)
		return (er);
	if (_strcmp(array[0], "exit") == 0) /*exit of the shell*/
		exit_cmd(array, rline, last_st);
	if (_strcmp(array[0], "env") == 0)
	{
		print_env();
		free(rline);
		free_arraybid(array);
		return (0);
	}
	path = _which(array[0], num); /*path ofr execve function*/
	if (path != NULL)
		flag = check_dir(array[0]);
	else
	{
		_which_errors(av, cont, array, rline);  /*includes freeing*/
		return (1);
	}
	last_st = child(path, array, rline, cont, av); /*Creates a child*/
	free(rline);  /*Freeing memory*/
	if (flag == 0) /*0 means allocated memory in path*/
		free(path);
	free_arraybid(array); /*freeing array*/
	return (last_st);
}
