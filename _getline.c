#include "simple_shell.h"
/**
 * _getline - read a new line form terminal
 * @inp: value of stream
 * Return: a new string with the input
 */
char *_getline(FILE *inp, int num)
{
	char *sline = NULL;
	ssize_t readed;
	size_t ln;

	readed = getline(&sline, &ln, inp);
	/*printf("sline %s\n", sline);*/
	if (readed == EOF)
	{
		if (num != 0) /*0 means non interactive mode*/
			_putchar('\n');
		free(sline);
		exit(50);
	}
	/*Checking errors input*/
	/*Type enter whitout writing something*/
	if (_strcmp(sline, "\n") == 0)
	{
		free(sline);
		return (NULL);
	}
	return (sline);
}
