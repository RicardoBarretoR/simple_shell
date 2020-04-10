#include "simple_shell.h"
/**
 * _getenv - searches for the environment string pointed to by name
 * @name: string containing the name of the requested variable
 * Return: succes null-terminated string with the value requested, NULL others
 */
char *_getenv(const char *name)
{
	char **arr, *dir, *dup;
	int i = 0, j = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] == environ[i][j])
				continue;
			else
				break;
		}
		if (environ[i][j] == '=' && name[j] == '\0')
		{
			dup = strdup(environ[i]);
			arr = sp_string(dup, "=");
			dir = strdup(arr[1]);
			/*Freeing arr*/
			free_arraybid(arr);
			/*Freeing dup*/
			free(dup);
			/*printf("%s", environ[i]);*/
			return (dir);
		}
	}
	return (NULL);
}
