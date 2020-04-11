#include "simple_shell.h"
/**
 * main - main function for the shell hsh
 * Return: 0 on success
 */
int main(void)
{
	int num;
	while (1)
	{
		num = isatty(STDIN_FILENO);
		printf("num = %d\n", num);
		if (num)
			hsh_loop(num);
		else
			hsh_loop(num);
	}
	return (0);
}
