#include "shell.h"
/**
 *print_prompt - print the prompt
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
