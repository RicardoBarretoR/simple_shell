#include "shell.h"
/**
 *_strdup - Function that copy a string
 *@str: pointer that point address of memory of string to be copied
 *Return: dup or NULL
 */
char *_strdup(const char *str)
{
	int i, size;
	char *dup;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
	}
	size = i;

	dup = malloc(sizeof(char) * (size + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}
/**
 *_strlen - return the length of a string
 *@str: pointer an string
 *Return: i
 */
int  _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
	}
	return (i);
}
