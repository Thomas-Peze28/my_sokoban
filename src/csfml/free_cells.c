/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

void free_csfml_cells(game_t *game)
{
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; x < game->width; x++) {
            sfRectangleShape_destroy(game->csfml->cells[y][x]);
        }
        free(game->csfml->cells[y]);
    }
    free(game->csfml->cells);
}
