/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int count_line(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buffer = NULL;
    size_t size = 0;
    int line_count = 0;

    if (fd == NULL)
        return -1;
    while ((getline(&buffer, &size, fd)) != -1)
        line_count++;
    free(buffer);
    fclose(fd);
    return line_count;
}

int get_max_length(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buffer = NULL;
    size_t size = 0;
    int length = 0;
    int max_length = 0;

    if (fd == NULL)
        return -1;
    while ((getline(&buffer, &size, fd)) != -1) {
        length = my_strlen(buffer);
        if (length > max_length)
            max_length = length;
    }
    free(buffer);
    fclose(fd);
    return max_length;
}
