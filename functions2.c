#include "shell.h"
/**
 *_strdup - Function that copy a string
 *@str: pointer that point address of memory of string to be copied
 *Return: dup or NULL
 */
char *_strdup(const char *str)
{
	int i, size;
	char *dup;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
	}
	size = i;

	dup = malloc(sizeof(char) * (size + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}
/**
 *_strlen - return the length of a string
 *@str: pointer an string
 *Return: i
 */
int  _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
	}
	return (i);
}
/**
  * _atoi - Convert a string to an integer.
  * @s: The string to be converted into int
  * Return: A integer
  */
int _atoi(char *s)
{
	int min = 1, id_i = 0, i = 0;
	unsigned int nu_i = 0;

	while (s[i])
	{
		if (s[i] == '-')
			min *= -1;

		while (s[i] >= '0' && s[i] <= '9')
		{
			id_i = 1;
			nu_i = (nu_i * 10) + (s[i] - '0');
			i++;
		}
		if (id_i == 1)
			break;

		i++;
	}

	nu_i *= min;
	return (nu_i);
}
/**
 *_isdigit - function that checks for a digit 0 through 9
 *@c: variable of a digit
 *Return: 1 - 0
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
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
