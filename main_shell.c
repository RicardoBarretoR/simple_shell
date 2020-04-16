#include "simple_shell.h"
/**
 * main - main function for the shell hsh
 * @ac: number of arguments input
 * @av: array with the arguments for non-interactive mode
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char *av[])
{
	int num, cont = 0, last_st = 0, last_r;

	while (1)
	{
		cont++;
		num = isatty(STDIN_FILENO);
		if (num)
			last_r = hsh_loop(num, cont, av, last_st);
		else
		{
			last_r = hsh_loop(num, cont, av, last_st);
		}
		last_st = last_r;
	}
	return (0);
}
