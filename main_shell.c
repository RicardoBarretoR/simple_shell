#include "shell.h"
/**
 * main - main program for the simple shell
 * @ac: number of arguments
 * @av: arguments
 * Return: Last status of the program
 */
int main(int ac __attribute__((unused)), char *av[])
{
	int ret_status = EXIT_SUCCESS;
	char *line = NULL, **array;
	size_t n = 0;
	int cont = 1;

	if (isatty(STDIN_FILENO))
		prompt();
	while (getline(&line, &n, stdin) != EOF)
	{
		/*add condition for enter*/
		/*(tokens)split the line string*/
		array = sp_string(line, " \n\t");
		if (array == NULL)
		{
			/*print error with perror*/
			ret_status = EXIT_FAILURE;
			continue;
		}
      		ret_status = child(array, av, cont);
		free(array);
		array = NULL;
		fflush(stdin); /*cleaning the buffer*/
		cont++;  /*counter*/
		if (isatty(STDIN_FILENO))
			prompt();
	}
	free(line);
	return (ret_status);
}
