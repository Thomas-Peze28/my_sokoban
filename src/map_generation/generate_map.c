/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int *find_random_space(char **map, int width, int height)
{
    int *coords = malloc(sizeof(int) * 2);
    int found = 0;

    if (!coords)
        return NULL;
    while (found == 0) {
        coords[0] = 1 + rand() % (width - 2);
        coords[1] = 1 + rand() % (height - 2);
        if (map[coords[1]][coords[0]] == ' ') {
            found = 1;
        }
    }
    return coords;
}

void place_boxes(char **map, int width, int height, int box_count)
{
    int *coords = NULL;

    for (int i = 0; i < box_count; i++) {
        coords = find_random_space(map, width, height);
        map[coords[1]][coords[0]] = 'X';
        free(coords);
    }
}

void place_storages(char **map, int width, int height, int box_count)
{
    int *coords = NULL;

    for (int i = 0; i < box_count; i++) {
        coords = find_random_space(map, width, height);
        map[coords[1]][coords[0]] = 'O';
        free(coords);
    }
}

char **generate_random_map(int width, int height, int box_count)
{
    char **map = malloc(sizeof(char *) * (height + 1));

    if (!map)
        return NULL;
    for (int y = 0; y < height; y++)
        map[y] = malloc(width + 1);
    map[height] = NULL;
    fill_borders(map, width, height);
    add_random_walls(map, width, height);
    place_player(map, width, height);
    place_boxes(map, width, height, box_count);
    place_storages(map, width, height, box_count);
    return map;
}
