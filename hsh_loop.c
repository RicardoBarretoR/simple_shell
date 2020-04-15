#include "simple_shell.h"

int hsh_loop(int num, int cont,char *av[], int last_st)
{
	char *rline = NULL, *path; /* *path*/
	char **array; /* **dirs */
	int ff, flag, r;

	if (num != 0)
	{
		signal(SIGINT, manage_signal);
		prompt(); /*print prompt*/
	}
	rline = _getline(stdin, num);
	if (rline == NULL)
	{
		free(rline);
		return (1);
	}
	/*replacing /t b spaces*/
        rline = replace_function(rline);
	/*spaces and tab errors with enter*/
	r = check_getline(rline);
        if (r == 0)
        {
                free(rline);
                return (last_st);
        }
	rline = strtok(rline, "\n\t"); /*Cleaning the \n\t*/
	if (rline == NULL)
	{
		free(rline);
		return (1);
	}
	ff = fflush(stdin); /*Cleaning the buffer*/
	array = sp_string(rline, " ");
	if (ff != 0)
	{
		free(rline);
		free_arraybid(array);
		perror("Error to flash the buffer");
		return (1);
	}
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
	{
		flag = check_dir(array[0]);
		/*printf("path %s\n", path);*/
	}
	else
	{
		/*Missing free memory when _which returns null*/
		_which_errors(av, cont, array, rline);
		return (1);
	}
	last_st = child(path, array, rline); /*Creates a child process*/
	/*Freeing memory*/
	free(rline);
	/*freeing path*/
	if (flag == 0) /*0 means allocated memory in path*/
		free(path);
	free_arraybid(array); /*freeing array*/
	return (last_st);
}
