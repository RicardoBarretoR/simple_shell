#include "simple_shell.h"

void hsh_loop(int num)
{
	char *rline = NULL; /* *path*/
	char **array; /* **dirs */
	int ff;

	if (num != 0)
		prompt(); /*print prompt*/
	rline = _getline(stdin);
	rline = strtok(rline, "\n"); /*Cleaning the /n*/
	ff = fflush(stdin); /*Cleaning the buffer*/
	if (ff != 0)
	{
		perror("Error to flash the buffer");
		exit(1);
	}
	/*path = _getenv("PATH");*/ /*getting the PATH variable*/
	/*double pointers*/
	array = sp_string(rline, " ");
	/*dirs = sp_string(path, ":");*/ /*USE OF PATH*/
	if (_strcmp(array[0], "exit") == 0) /*exit of the shell*/
	{
		free(rline);
		free_arraybid(array);
		exit(EXIT_SUCCESS);
	}
	child(array, rline); /*Creates a child process*/
	/*Freeing memory*/
	free(rline);
	/*free(path);*/
	free_arraybid(array); /*freeing array*/
	/**
	 *free_arraybid(array);
	 *free_arraybid(dirs);
	 *for (i = 0; dirs[i] != NULL; i++)
	 *free(dirs[i]);
	 *free(dirs);
	 */
}
