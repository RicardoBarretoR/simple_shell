#include "shell.h"
/**
 * print_errors - print errors of the program
 * @array: array of comand and arguments
 * @av: array from main
 * @cont: count the number prompts
 * @num: indicates the error
 * Return: Nothing
 */
void print_errors(char **array, char *av[], int cont, int num)
{
	int lnav, lnarray;

	lnarray = _strlen(array[0]);
	lnav = _strlen(av[0]);

	if (num == 127 || num == 126)
	{
		write(STDOUT_FILENO, av[0], lnav);
		write(STDOUT_FILENO, " : ", 3);
		print_integer(cont);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, array[0], lnarray);
		write(STDOUT_FILENO, ": ", 2);
		perror("");
	}

	if (num == 2)
	{
		write(STDOUT_FILENO, av[0], lnav);
		write(STDOUT_FILENO, ": ", 2);
	}
}
/**
 *print_integer - call a recursion function with an iterator
 *@n: number to print
 *Return: lenght of the number
 */
int print_integer(int n)
{
	int i = 1;

	return (recursion_int(n, i));
}
/**
 *recursion_int - print
 *@n: receive a number
 *@cont: count the lenght of number
 *Return: Amount of digits of the number n
 */
int recursion_int(int n, int cont)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = (-1) * n;
		cont++;
	}
	else
		num = n;

	if (num / 10)
	{
		cont = recursion_int(num / 10, cont = cont + 1);
	}
	_putchar((num % 10) + '0');
	return (cont);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
