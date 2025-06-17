/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

void print_win(game_t *game)
{
    if (check_win(game) != 1)
        return;
    sleep(2);
    clear();
    mvprintw(LINES / 2, COLS / 2 - 5, "You Win!");
    play_sound("assets/victory.wav");
    refresh();
    nodelay(stdscr, FALSE);
    getch();
}

int check_box_valid(game_t *game, int y, int x)
{
    if (game->map[y][x] == 'X' && game->map_copy[y][x] == 'O')
        game->valid_boxes++;
    return 0;
}

int check_win(game_t *game)
{
    game->valid_boxes = 0;
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; game->map[y][x] != '\0'; x++)
            check_box_valid(game, y, x);
    }
    if (game->valid_boxes == game->storage_count)
        return 1;
    return 0;
}
