/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

void free_map_copy(char **map_copy, int i)
{
    for (int j = 0; j < i; j++)
        free(map_copy[j]);
    free(map_copy);
}

int copy_map(game_t *game)
{
    if (game->map_copy != NULL) {
        free_map_copy(game->map_copy, game->height);
        game->map_copy = NULL;
    }
    game->map_copy = malloc(sizeof(char *) * (game->height + 1));
    if (game->map_copy == NULL)
        return 84;
    for (int i = 0; i < game->height; i++) {
        game->map_copy[i] = my_strdup(game->map[i]);
        if (game->map_copy[i] == NULL) {
            free_map_copy(game->map_copy, i);
            return 84;
        }
    }
    game->map_copy[game->height] = NULL;
    return 0;
}
