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
int check_getline(char *rline)
{
	int i, valid_char = 0;

	/*solving spaces spaces + enter, tab tab + enter   errors*/
	for (i = 0; rline[i] != '\0'; i++)
	{
		if (rline[i] != ' ' && rline[i] != '\n' && rline[i] != '\t')
		{
			valid_char = 1;
		}
	}
	return (valid_char);
}
char *replace_function(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
		{
			str[i] = ' ';
		}
		if (str[i] != ' ' && str[i] != '\t')
			break;
		i++;
	}
	return (str);
}
void manage_signal(int num_s __attribute__((unused)))
{
	_putchar('\n');
	prompt();
	return;
}
