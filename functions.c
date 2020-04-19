#include "shell.h"

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
	char *tok;
	int i = 0;

	/*Crear array doble con malloc*/
	tokens = (char **) malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		/*Print error for malloc*/
		return (NULL);
	}
	tok = strtok(string, del); /*primer token del string*/
	while (tok != NULL)
	{
		/*crear columnas*/
		tokens[i] = tok;
		tok = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
