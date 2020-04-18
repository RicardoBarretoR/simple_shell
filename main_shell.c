#include "shell.h"
/**
 * main - main program for the simple shell
 * Return: Last status of the program
 */
int main(void)
{
	int return_status = EXIT_SUCCESS;
	char *line = NULL, **array;
	size_t n = 0;
	int i = 0;

	if (isatty(STDIN_FILENO))
		prompt();
	while(getline(&line, &n, stdin) != EOF)
	{
		/*add condition for enter*/
		/*(tokens)split the line string*/
		array = sp_string(line, " \n\t");
		i = 0;
		while (array[i] != NULL)
		{
			printf("%s\n", array[i]);
			i++;
		}
		free_arraybid(array);
		fflush(stdin); /*cleaning the buffer*/
		if (isatty(STDIN_FILENO))
			prompt();
	}
	free(line);
	return (return_status);
}
