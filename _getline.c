#include "simple_shell.h"
/**
 * _getline - read a new line form terminal
 * @inp: value of stream
 * @num: indicates the interactive or non-interactive mode
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
		exit(0);  /*was 127*/
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
/**
 * cases_command - checks special cases for the main command
 * @av: arguments from main
 * @cont: count the number of cycles
 * @array: string to be checked
 * @rline: line to free
 * Return: on succes 0, 1 otherwise
 */
int cases_command(char *av[], int cont, char **array, char *rline)
{
	/*char *s[] = {"..", "."};*/
	int i, cont_slash = 0, letter = 0;

	/*checking . .. y / like a command*/
	for (i = 0; array[0][i] != '\0'; i++)
	{
		if (array[0][i] == '/')
			cont_slash++;
		if (array[0][i] != '/')
			letter++;
	}
	if (cont_slash == 1 && letter == 0)
	{
		no_permission(av, cont, array, rline);
		return (126);
	}
	return (0);
}
/**
 * check_getline - checks the getline input to solve some errors
 * @rline: string from the getline function
 * Return: on succes returns 1, otherwise 0
 */
int check_getline(char *rline)
{
	int i, valid_char = 0;

	/*solving spaces spaces + enter, tab tab + enter   errors*/
	for (i = 0; rline[i] != '\0'; i++)
	{
		if (rline[i] != ' ' && rline[i] != '\n'
			&& rline[i] != '\t' && rline[i] != '.')
		{
			valid_char = 1;
		}
	}
	return (valid_char);
}
/**
 * replace_function - This function replaces \t by spaces ' '
 * @str: string to check
 * Return: the same string with the corrections
 */
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
/**
 * manage_signal - function to manage the signal CTRL + C
 * @num_s: number for the signal number
 * Return: Nothing
 */
void manage_signal(int num_s __attribute__((unused)))
{
	_putchar('\n');
	prompt();
}
