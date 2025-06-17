/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int is_file_exists(const char *filepath)
{
    FILE *file = fopen(filepath, "r");

    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

int have_sound_file(void)
{
    if (is_file_exists("assets/footstep.wav"))
        return 1;
    if (is_file_exists("assets/collision.wav"))
        return 1;
    if (is_file_exists("assets/victory.wav"))
        return 1;
    return 0;
}
