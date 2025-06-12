/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int check_player_move(int ch, game_t *game)
{
    if (ch == KEY_UP)
        move_player(game, -1, 0);
    if (ch == KEY_DOWN)
        move_player(game, 1, 0);
    if (ch == KEY_LEFT)
        move_player(game, 0, -1);
    if (ch == KEY_RIGHT)
        move_player(game, 0, 1);
    return 0;
}
