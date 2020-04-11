#include "simple_shell.h"

char *_which(char *cmd)
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
	return (cmd_exe);
}
