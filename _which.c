#include "simple_shell.h"

char *_which(char *cmd)
{
	struct stat st;
	char **paths;
	char *s, *pt = NULL;
	int j = 0, lg, lg2;

	pt = _getenv("PATH");
	printf("pt: %s\n", pt);
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
			while(paths[j] != NULL)
			{
				free(paths[j]);
				j++;
			}
			free(paths);
			/*freeing pt*/
			free(pt);
			printf("%s", s);
			printf(" FOUND\n");
			return (s);
		}
		else
		{
			printf("NOT FOUND\n");
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
int main(void)
{
	char *wh;
	char *cmd = "ca1";

	wh = _which(cmd);
	if (wh == NULL)
	{
		printf("wh is NULL\n");
	}
	else
	{
		printf("wh %s\n", wh);
	}
	free(wh);
	return (0);
}
