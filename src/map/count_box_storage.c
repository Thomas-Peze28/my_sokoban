/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int update_count(game_t *game, int y, int x)
{
    if (game->map[y][x] == 'O')
        game->storage_count++;
    if (game->map[y][x] == 'X')
        game->box_count++;
    return 0;
}

int count_storage(game_t *game)
{
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; game->map[y][x] != '\0'; x++) {
            update_count(game, y, x);
        }
    }
    return 0;
}
