/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int color_cell(char cell, int y, int x)
{
    if (cell == '#') {
        attron(COLOR_PAIR(1));
        mvaddch(y, x, cell);
        attroff(COLOR_PAIR(1));
        return 0;
    }
    if (cell == 'P') {
        attron(COLOR_PAIR(2));
        mvaddch(y, x, cell);
        attroff(COLOR_PAIR(2));
        return 0;
    }
    if (cell == 'X') {
        attron(COLOR_PAIR(3));
        mvaddch(y, x, cell);
        attroff(COLOR_PAIR(3));
        return 0;
    }
    mvaddch(y, x, cell);
    return 0;
}

int display_map(game_t *game)
{
    int term_height = 0;
    int term_width = 0;

    clear();
    getmaxyx(stdscr, term_height, term_width);
    if (term_height < game->height || term_width < game->width) {
        mvprintw(term_height / 2, term_width / 2 - 10, "Window too small !");
        refresh();
        return 1;
    }
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; game->map[y][x] != '\0'; x++) {
            color_cell(game->map[y][x], y, x);
        }
    }
    refresh();
    return 0;
}
