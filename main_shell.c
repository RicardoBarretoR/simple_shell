#include "simple_shell.h"

int main(void)
{
	char *rline = NULL, *path;
        char **array, **dirs;
        int exe, wt, child, status, i, cont = 0;

        while (1)
        {
                printf("#cisfun$ ");
		rline = _getline(stdin);
                rline = strtok(rline, "\n"); /*Cleaning the /n*/
		printf("\nrline %s\n", rline);
		/*PATH*/
		path = _getenv("PATH");
		/*double pointers*/
                array = sp_string(rline, " ");
		dirs = sp_string(path, ":");
		if (cont > 0)
			printf("cont2 = %d\n", cont);
		/*for (i = 0; dirs[i] != NULL; i++)
                {
                        printf("%s\n", dirs[i]);
			}*/
		/*If we use the command which*/
		/*printf("_which(%s)\n", array[1]);
		wh = _which(array[0]);
		if (wh != NULL)
		{
			printf("%s\n", wh);
		}
		else
		{
			printf("\nwh is NULL\n");
			}
		free(wh);*/
		child = fork();
		if (child == 0)
		{
			printf("exe %s\n", array[0]);
			exe = execve(array[0], array, NULL);
			if (exe == -1)
			{
				for (i = 0; array[i] != NULL; i++)
				{
					free(array[i]);
				}
				perror("Error with execve");
				free(array);
				free(rline);
				_exit(1);
			}
		}
		else if(child > 0)
		{
			wt = wait(&status);
			if (wt < 0)
			{
				perror("Error with wait");
				exit(1);
			}
		}
		else
		{
			perror("Error with fork");
			exit(1);
		}
		/*Freeing memory*/
		free(rline);
		free(path);
		for (i = 0; array[i] != NULL; i++)
		{
			free(array[i]);
		}
		free(array);
		/*free_arraybid(array);
		  free_arraybid(dirs);*/
		for (i = 0; dirs[i] != NULL; i++)
			free(dirs[i]);
		free(dirs);
		cont++;
		printf("cont = %d\n", cont);
	}
	printf("Exit\n");
	return (0);
}
