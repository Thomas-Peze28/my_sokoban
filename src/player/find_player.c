/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

void check_player_position(game_t *game, int y, int x)
{
    if (game->map[y][x] == 'P') {
        game->player_y = y;
        game->player_x = x;
    }
}

void find_player(game_t *game)
{
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; game->map[y][x] != '\0'; x++) {
            check_player_position(game, y, x);
        }
    }
}
