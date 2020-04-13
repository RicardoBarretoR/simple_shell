#include "simple_shell.h"
/**
 * _puts - Prints a string
 * @str: string to print
 * Return: Nothing
 */
void _puts(char *str)
{
	int m = 0;

	for (m = 0; str[m] != '\0'; ++m)
	{
		_putchar(str[m]);
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
		putchar(45);
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
