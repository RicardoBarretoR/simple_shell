#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void prompt(void);
char **sp_string(char *string, char *del);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *string, char *stradd);
char *_strdup(const char *str);
int _strlen(char *str);

#endif
