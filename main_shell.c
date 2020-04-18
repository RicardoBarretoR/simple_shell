/**
 * main - main program for the simple shell
 * Return: Last status of the program
 */
int main(void)
{
	int return_status = EXIT_SUCCESS;
	char *line = NULL;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
		prompt();
	while(getline(&line, &n, stdin) != EOF)
	{
		/*add condition for enter*/
		/*(tokens)split the line string*/
	}
	return (return_status);
}
