/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** Allocate memory and copy a string in it
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *src)
{
    int len = 0;
    char *dest = NULL;

    if (!src)
        return NULL;
    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    if (!dest)
        return NULL;
    for (int count = 0; count < len; count++)
        dest[count] = src[count];
    dest[len] = '\0';
    return dest;
}
