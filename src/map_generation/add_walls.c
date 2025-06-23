/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

void add_wall(char **map, int coords[2], int width, int height)
{
    int x = coords[0];
    int y = coords[1];

    if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
        map[y][x] = '#';
    else
        map[y][x] = ' ';
}

void fill_borders(char **map, int width, int height)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++)
            add_wall(map, (int[]){x, y}, width, height);
        map[y][width] = '\0';
    }
}

void add_random_walls(char **map, int width, int height)
{
    int wall_count = (width * height) / 8;
    int x = 0;
    int y = 0;

    for (int i = 0; i < wall_count; i++) {
        x = rand() % (width - 2) + 1;
        y = rand() % (height - 2) + 1;
        map[y][x] = '#';
    }
}
