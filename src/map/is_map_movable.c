/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int is_box_movable(game_t *game, int x, int y)
{
    if (x <= 0 || x >= game->width - 1 || y <= 0 || y >= game->height - 1) {
        return 0;
    }
    if ((game->map[y][x - 1] == ' ' || game->map[y][x - 1] == 'O'
        || game->map[y][x - 1] == 'P') &&
        (game->map[y][x + 1] == ' ' || game->map[y][x + 1] == 'O'
        || game->map[y][x + 1] == 'P')) {
        return 1;
    }
    if ((game->map[y - 1][x] == ' ' || game->map[y - 1][x] == 'O'
        || game->map[y - 1][x] == 'P') &&
        (game->map[y + 1][x] == ' ' || game->map[y + 1][x] == 'O'
        || game->map[y + 1][x] == 'P')) {
        return 1;
    }
    return 0;
}

int check_if_box(game_t *game, int coords[2], int *total_boxes,
    int *blocked_boxes)
{
    if (game->map[coords[1]][coords[0]] == 'X'
        && game->map_copy[coords[1]][coords[0]] != 'O') {
        (*total_boxes)++;
        (*blocked_boxes) += !is_box_movable(game, coords[0], coords[1]);
    }
    return 0;
}

int is_all_boxes_movable(game_t *game)
{
    int blocked_boxes = 0;
    int total_boxes = 0;

    for (int y = 0; y < game->height; y++) {
        for (int x = 0; x < game->width; x++)
            check_if_box(game, (int[2]){x, y}, &total_boxes, &blocked_boxes);
    }
    if (blocked_boxes == total_boxes && total_boxes > 0)
        return 1;
    return 0;
}
