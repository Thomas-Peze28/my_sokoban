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
    #include <time.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #define WIN_WIDTH  1000
    #define WIN_HEIGHT 1000

typedef struct csfml_s {
    sfRenderWindow *window;
    sfEvent event;
    sfFont *font;
    sfText *text;
    int width;
    int height;
    sfTexture *wall_texture;
    sfTexture *player_texture;
    sfTexture *box_texture;
    sfTexture *storage_texture;
    sfTexture *floor_texture;
    sfSprite ***cells_sprites;
} csfml_t;

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
    time_t start_time;
    double elapsed_time;
    csfml_t *csfml;
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
void play_sound(const char *filename);
int have_sound_file(void);
int is_file_exists(const char *filepath);

sfColor get_csfml_color(char cell);
int have_csfml_flag(int argc, char **argv);
int init_csfml(game_t *game);
int display_map_csfml(game_t *game);
void free_map(char **map, int height);
void free_csfml_cells(game_t *game);
int csfml_game_loop(game_t *game);
int print_win_csfml(game_t *game);
void draw_cell(game_t *game, int coords[2], float cell_size, float offsets[2]);
char **generate_random_map(int width, int height, int box_count);
void print_lose(game_t *game);

int map_have_player(char **map, int width, int height);
void check_player_space(char **map, int coords[2], int width, int height);
void place_player(char **map, int width, int height);
void add_wall(char **map, int coords[2], int width, int height);
void fill_borders(char **map, int width, int height);
void add_random_walls(char **map, int width, int height);
void place_boxes_and_storages(char **map, int width,
    int height, int box_count);
int have_random_flag(char **argv);
int is_all_boxes_movable(game_t *game);
int print_lose_csfml(game_t *game);

#endif /* SOKOBAN_H */
