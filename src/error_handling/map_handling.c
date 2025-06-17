/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int have_player(game_t *game, int y, int x)
{
    if (game->map[y][x] == 'P')
        return 1;
    return 0;
}

int count_player(game_t *game)
{
    int player_count = 0;

    for (int y = 0; y < game->height; y++) {
        for (int x = 0; game->map[y][x] != '\0'; x++) {
            player_count += have_player(game, y, x);
        }
    }
    return player_count;
}

int check_map_elements(game_t *game)
{
    if (game->map == NULL)
        return 84;
    if (game->box_count == 0) {
        my_putstr("Error: No boxes found.\n");
        return 84;
    }
    if (game->storage_count == 0) {
        my_putstr("Error: No storage locations found.\n");
        return 84;
    }
    if (game->storage_count != game->box_count) {
        my_putstr("Error: Not all boxes have storage.\n");
        return 84;
    }
    if (count_player(game) != 1) {
        my_putstr("Error: Invalid number of players.\n");
        return 84;
    }
    return 0;
}

int error_handling(game_t *game)
{
    int result = check_map_elements(game);

    if (result != 0)
        return result;
    if (have_sound_file() == 0) {
        my_putstr("Warning: No sound files found.\n");
    }
    return 0;
}
