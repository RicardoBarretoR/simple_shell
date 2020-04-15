#include "simple_shell.h"
/**
 * _which_errors - check and prints errors in _which function
 * @av: array of pointers of the main function
 * @cont: amount of iterations of the loop
 * @array: array with the command and arguments
 * @rline: input from the getline
 * Return: Nothing
 */
void _which_errors(char *av[], int cont, char **array, char *rline)
{
	free(rline);
	_puts(av[0]);
	_putchar(':');
	_putchar(' ');
	/*prints the number cont*/
	print_integer(cont);
	_putchar(':');
	_putchar (' ');
	_puts(array[0]);
	_putchar(':');
	_puts(" not found");
	_putchar('\n');
	free_arraybid(array);
}
