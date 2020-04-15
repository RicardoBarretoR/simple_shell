#include "simple_shell.h"

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
