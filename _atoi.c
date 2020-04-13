#include "simple_shell.h"
/**
  * _atoi - Convert a string to an integer.
  * @s: The pointer to convert
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
