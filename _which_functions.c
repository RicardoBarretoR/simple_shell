#include "simple_shell.h"
/**
 * _which_dir - case when cmd is a directory
 * @cmd: directory
 * Return: on success path of command, NULL otherwise
 */
char *_which_dir(char *cmd)
{
	struct stat st;
	char **paths;
	char *pt = NULL;
	int j = 0;

	pt = _getenv("PATH");
	/*added*/
	paths = sp_string(pt, ":");
	j = 0;
	while (paths[j] != NULL)
	{
		if (_strcmp(cmd, paths[j]) == 0)
		{
			if (stat(cmd, &st) == 0)
			{
				/*freeing missing values of paths*/
				while (paths[j] != NULL)
				{
					free(paths[j]);
					j++;
				}
				free(paths);
				/*freeing pt*/
				free(pt);
				/*printf("%s", cmd);*/
				/*printf(" FOUND\n");*/
				return (cmd);
			}
			else
			{
				/*printf("NOT FOUND\n");*/
			}
		}
		else
			/*printf("NOT F\n");*/
		/*printf("%s ", s);*/
		/*freeing paths used*/
		free(paths[j]);
		j++;
	}
	/*freeing in case that the paths does not exist*/
	free(paths);
	free(pt);
	return (NULL);
}
/**
 * _which_cmd - case when cmd is a command
 * @cmd: command
 * Return: on success path of command, NULL otherwise
 */
char *_which_cmd(char *cmd)
{
	struct stat st;
	char **paths;
	char *s, *pt = NULL;
	int j = 0, lg, lg2;

	pt = _getenv("PATH");
	/*added*/
	paths = sp_string(pt, ":");
	j = 0;
	while (paths[j] != NULL)
	{
		lg = 0;
		while (paths[j][lg] != '\0')
			lg++;
		lg2 = 0;
		while (cmd[lg2] != '\0')
			lg2++;
		/*Allocating memory for the path*/
		s = malloc(sizeof(char) * (lg + 2 + lg2));
		s = _strcpy(s, paths[j]);
		s = _strcat(s, "/");
		s = _strcat(s, cmd);
		/*printf("%s ", s);*/
		if (stat(s, &st) == 0)
		{
			/*freeing missing values of paths*/
			while (paths[j] != NULL)
			{
				free(paths[j]);
				j++;
			}
			free(paths);
			/*freeing pt*/
			free(pt);
			/*printf("%s", s);*/
			/*printf(" FOUND\n");*/
			return (s);
		}
		else
		{
			/*printf("NOT FOUND\n");*/
		}
		/*freeing paths used*/
		free(paths[j]);
		j++;
		free(s);
	}
	/*freeing in case that the paths does not exist*/
	free(paths);
	free(pt);
	return (NULL);
}
/**
 * check_dir - checks if cmd is a command or a directory
 * @cmd: command or directory
 * Returnd: 1 if cmd is a directory, 0 if it's a command
 */
int check_dir(char *cmd)
{
	int i, flag_dir = 0;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
		{
			flag_dir = 1;
			return (flag_dir);
		}
	}
	return (flag_dir);
}
