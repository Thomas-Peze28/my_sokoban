/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Display number
*/

#include "my.h"

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int new_indices(char const *str, int *start, int *end)
{
    *start = 0;
    *end = my_strlen(str) - 1;
    while (is_space(str[*start]))
        (*start)++;
    while (*end >= *start && is_space(str[*end]))
        (*end)--;
    return (*end - *start + 1);
}

void replace_char(int start, char *str, char *result, int i)
{
    if (is_space(str[start]))
        result[i] = ' ';
    else
        result[i] = str[start];
}

char *clean_str(char *str)
{
    int len = my_strlen(str);
    int start = 0;
    int end = len - 1;
    int new_len = 0;
    char *result = NULL;
    int i = 0;
    int was_space = 0;

    new_len = new_indices(str, &start, &end);
    result = malloc(new_len + 1);
    while (start <= end) {
        if (!is_space(str[start]) || was_space == 0) {
            replace_char(start, str, result, i);
            i++;
        }
        was_space = is_space(str[start]);
        start++;
    }
    result[i] = '\0';
    return result;
}
