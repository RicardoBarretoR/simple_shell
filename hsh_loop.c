#include "simple_shell.h"

int hsh_loop(int num, int cont,char *av[], int last_st)
{
	char *rline = NULL, *path; /* *path*/
	char **array; /* **dirs */
	int ff, flag;

	/*printf("last_st %d\n", last_st);*/
	if (num != 0)
		prompt(); /*print prompt*/
	rline = _getline(stdin, num);
	if (rline == NULL)
		return (1);
	rline = strtok(rline, "\n"); /*Cleaning the /n*/
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
	path = _which(array[0]); /*path ofr execve function*/
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
