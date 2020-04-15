#include "simple_shell.h"
/**
 * free_list - free the memory
 * @head: the lis for the estruct
 */
void free_list(list_t *head)
{
	if (head == NULL)
		return;
	if ((*head).next != NULL)
		free_list((*head).next);
	free((*head).str);
	free(head);
}

/**
 * _strcmp - compare 2 strings
 * @s1: string to compare
 * @s2: string to compare
 * Return: 0 on success, another number in otherwise cases
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int val;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			val = 0;
		else
		{
			val = (s1[i] - '0') - (s2[i] - '0');
			return (val);
		}
		i++;
	}

	return (val);
}
/**
 * _strcpy - copies the string pointed to by src
 * @dest: where string will be copy
 * @src: string to copy
 * Return: dest string
 */
char *_strcpy(char *dest, char *src)
{
	int x, j;

	for (x = 0; src[x] != '\0'; x++)
	{
	}
	for (j = 0; j < x; j++)
		dest[j] = src[j];
	dest[j] = '\0';

	return (dest);

}
/**
 * _strcat - concatenatetwo strings
 * @string: main string
 * @stradd: string to add to string parameter
 * Return: a string concatenated on success
 */
char *_strcat(char *string, char *stradd)
{
	int i = 0, j = 0;

	while (string[i] != '\0')
		i++;
	while (stradd[j] != '\0')
	{
		string[i] = stradd[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}
/**
 * sp_string - Split a string with strtok function
 * @string: string to be splitted
 * @del: delimitators for the string
 * Return: a double pointer array with the string splitted
 */
char **sp_string(char *string, char *del)
{
	char **tokens;
	/*char string[] = "Hola como";*/
	char *scopy = NULL;
	char *tokcont, *tok;
	int lentok = 0, i = 0, nwords = 0;

	/*copying the original string to scopy*/
	scopy = _strdup(string);
	/*Conteo de palabras*/
	tokcont = strtok(scopy, del);
	while (tokcont != NULL)
	{
		nwords++;
		tokcont = strtok(NULL, del);
	}
	free(scopy); /*leak # 1*/
	/*printf("nwords = %d", nwords);*/
	/*Crear array doble con malloc*/
	tok = strtok(string, del); /*primer token del string*/
	tokens = (char **) malloc(sizeof(char *) * (nwords + 1));
	for (i = 0; i < nwords; i++)
	{
		lentok = 0;
		while (tok[lentok] != '\0') /*longitud del token*/
			lentok++;
		/*crear columnas*/
		tokens[i] = _strdup(tok);
		tok = strtok(NULL, del);
	}
	tokens[i] = NULL;
	return (tokens);
}
