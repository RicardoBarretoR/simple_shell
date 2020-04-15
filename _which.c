#include "simple_shell.h"
/**
 * _which - Checks if the command is valid or non-valid
 * @cmd: command or path to check
 * @num: indicates the interactive or non-interactive mode
 * Return: success the path to be executed, NULL otherwvise
 */
char *_which(char *cmd, int num)
{
	int flag;
	char *cmd_exe;

	flag = check_dir(cmd);
	if (flag == 1)
	{
		/*directories*/
		cmd_exe = _which_dir(cmd);
	}
	else
	{
		/*command*/
		cmd_exe = _which_cmd(cmd);
	}
	if (cmd_exe != NULL && num == 0)
		prompt();
	return (cmd_exe);
}
