/*
** EPITECH PROJECT, 2025
** include
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H
    #define  SOKOBAN_H

    #include "my.h"
    #include <ncurses.h>


typedef struct game_s {
    char **map;
    char **map_copy;
    int height;
    int width;
    int player_x;
    int player_y;
    int box_count;
    int storage_count;
    int valid_boxes;
    int move_count;
} game_t;


int count_line(char *filepath);
int get_max_length(char *filepath);
char **load_map(char *filepath, game_t *game);
int copy_map(game_t *game);
void find_player(game_t *game);
int init_ncurses(void);
int check_win(game_t *game);
void move_player(game_t *game, int dy, int dx);
int check_player_move(int ch, game_t *game);
int color_cell(char cell, int y, int x);
int display_map(game_t *game);
int game_loop(game_t *game);
void print_help(void);
int count_storage(game_t *game);
void print_win(game_t *game);
int argc_error_handling(int argc, char **argv);
int error_handling(game_t *game);
int init_game(game_t *game, char **argv);
void reset_game(game_t *game);

#endif /* SOKOBAN_H */
