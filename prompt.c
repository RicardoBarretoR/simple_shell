#include "simple_shell.h"
/**
 * prompt - prints prompt line
 * Return: Nothing
 */
void prompt(void)
{
	int i = 0;
	char *s = "$ ";

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
}
