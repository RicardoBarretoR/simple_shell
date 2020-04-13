#include "simple_shell.h"

void print_env()
{
	int j = 0, i = 0;

        while (environ[i] != NULL)
        {
		j = 0;
		while (environ[i][j] != '\0')
		{
			_putchar(environ[i][j]);
			j++;
		}
		_putchar('\n');
                i++;
        }
}
