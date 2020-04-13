#include "simple_shell.h"

void hsh_loop(int num, int cont,char *av[])
{
	char *rline = NULL, *path; /* *path*/
	char **array; /* **dirs */
	int ff, flag;

	if (num != 0)
		prompt(); /*print prompt*/
	rline = _getline(stdin, num);
	if (rline == NULL)
		return;
	rline = strtok(rline, "\n"); /*Cleaning the /n*/
	ff = fflush(stdin); /*Cleaning the buffer*/
	array = sp_string(rline, " ");
	if (ff != 0)
	{
		perror("Error to flash the buffer");
		exit(1);
	}
	if (_strcmp(array[0], "exit") == 0) /*exit of the shell*/
		exit_cmd(array, rline);
	if (_strcmp(array[0], "env") == 0)
	{
		print_env();
		free(rline);
		free_arraybid(array);
		return;
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
		return;
	}
	child(path, array, rline); /*Creates a child process*/
	/*Freeing memory*/
	free(rline);
	/*freeing path*/
	if (flag == 0) /*0 means allocated memory in path*/
		free(path);
	free_arraybid(array); /*freeing array*/
}
