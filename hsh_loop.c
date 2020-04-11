#include "simple_shell.h"

void hsh_loop(int num)
{
	char *rline = NULL, *path; /* *path*/
	char **array; /* **dirs */
	int ff, flag;

	if (num != 0)
		prompt(); /*print prompt*/
	rline = _getline(stdin);
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
	path = _which(array[0]); /*path ofr execve function*/
	if (path != NULL)
	{
		flag = check_dir(array[0]);
		printf("path %s\n", path);
	}
	else
	{
		perror("_which return null\n");
		return;
	}
	if (_strcmp(array[0], "exit") == 0) /*exit of the shell*/
	{
		free(rline);
		free_arraybid(array);
		exit(EXIT_SUCCESS);
	}
	child(path, array, rline); /*Creates a child process*/
	/*Freeing memory*/
	free(rline);
	/*freeing path*/
	if (flag == 0) /*0 means allocated memory in path*/
		free(path);
	free_arraybid(array); /*freeing array*/
	/**
	 *free_arraybid(array);
	 *free_arraybid(dirs);
	 *for (i = 0; dirs[i] != NULL; i++)
	 *free(dirs[i]);
	 *free(dirs);
	 */
}
