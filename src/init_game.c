/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int init_game(game_t *game, char **argv)
{
    game->map = NULL;
    game->map_copy = NULL;
    game->player_x = 0;
    game->player_y = 0;
    game->box_count = 0;
    game->storage_count = 0;
    game->valid_boxes = 0;
    game->move_count = 0;
    game->height = count_line(argv[1]);
    game->width = get_max_length(argv[1]);
    load_map(argv[1], game);
    count_storage(game);
    copy_map(game);
    find_player(game);
    return 0;
}

void reset_game(game_t *game)
{
    for (int i = 0; i < game->height; i++)
        for (int j = 0; game->map[i][j] != '\0'; j++)
            game->map[i][j] = game->map_copy[i][j];
    find_player(game);
    game->move_count = 0;
    game->start_time = time(NULL);
}
