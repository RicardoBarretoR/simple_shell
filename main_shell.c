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
	int cnt = 1;

	if (isatty(STDIN_FILENO))
		prompt();
	while (getline(&line, &n, stdin) != EOF)
	{
		array = sp_string(line, " \n\t");
		if (array == NULL || array[0] == NULL)
		{
			/*print error with perror*/
			free(array);
			ret_status = EXIT_FAILURE;
			cnt++;
			if (isatty(STDIN_FILENO))
				prompt();
			continue;
		}
		if (_strcmp(array[0], "exit") == 0)
			ret_status = exit_cmd(array, av, line, cnt, ret_status);
		if (_strcmp(array[0], "env") == 0)
		{
			ret_status = print_env();
			free(array);
			if (isatty(STDIN_FILENO))
				prompt();
			continue;
		}
		ret_status = child(array, av, cnt);
		free(array);
		array = NULL;
		fflush(stdin); /*cleaning the buffer*/
		cnt++;  /*counter*/
		if (isatty(STDIN_FILENO))
			prompt();
	}
	free(line);
	return (ret_status);
}
