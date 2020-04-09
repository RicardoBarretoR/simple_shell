#include "simple_shell.h"
/**
 * _getline - read a new line form terminal
 * @inp: value of stream
 * Return: a new string with the input
 */
char *_getline(FILE *inp)
{
        char *sline = NULL;
        ssize_t readed;
        size_t ln;

        readed = getline(&sline, &ln, inp);
        if (readed == -1)
        {
                free(sline);
                exit(EXIT_FAILURE);
        }
        return (sline);
}
