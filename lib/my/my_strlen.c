/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** Display len of a string
*/

#include "my.h"

int my_strlen(const char *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}
