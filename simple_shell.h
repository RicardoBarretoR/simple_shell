#ifndef _HOLBERTON_
#define _HOLBERTON_
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/*extern environment variable*/
extern char **environ;
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
/*Help functions*/
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *string, char *stradd);
char **sp_string(char *string, char *del);

/*environment and PATH functions*/
char *_getenv(const char *name);
char *_getline(FILE *inp);
char *_which(char *cmd);
/*Main program functions*/
void hsh_loop(int num);
void prompt(void);
void child(char **array, char *rline);

/*list functions*/
list_t *add_node(list_t **head, const char *str);
size_t print_list(const list_t *h);
int linked_listpath(char *path);
/*Free functions*/
void free_list(list_t *head);
void free_arraybid(char **array);

#endif
