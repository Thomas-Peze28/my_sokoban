/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int is_player(char **map, int x, int y)
{
    if (map[y][x] == 'P')
        return 1;
    return 0;
}

int map_have_player(char **map, int width, int height)
{
    int count = 0;

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++)
            count += is_player(map, x, y);
    }
    if (count != 0) {
        return 1;
    }
    return 0;
}

void check_player_space(char **map, int coords[2], int width, int height)
{
    int x = coords[0];
    int y = coords[1];

    if (map[y][x] == ' ' && !map_have_player(map, width, height)) {
        map[y][x] = 'P';
        return;
    }
}

void place_player(char **map, int width, int height)
{
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++)
            check_player_space(map, (int[]){x, y}, width, height);
    }
}
