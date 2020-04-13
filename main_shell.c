#include "simple_shell.h"
/**
 * main - main function for the shell hsh
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char *av[])
{
	int num, cont = 0;
	while (1)
	{
		cont++;
		num = isatty(STDIN_FILENO);
		if (num)
			hsh_loop(num, cont, av);
		else
		{
			hsh_loop(num, cont, av);
		}
	}
	return (0);
}
