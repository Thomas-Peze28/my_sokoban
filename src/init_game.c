/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int have_random_flag(char **argv)
{
    for (int i = 1; argv[i] != NULL; i++) {
        if (strcmp(argv[i], "-r") == 0)
            return 1;
    }
    return 0;
}

void choose_flags(char **argv, game_t *game, int max_boxes, int box_count)
{
    if (have_random_flag(argv)) {
        srand(time(NULL));
        game->width = (rand() % 21) + 10;
        game->height = (rand() % 11) + 8;
        max_boxes = (game->width * game->height) / 10;
        box_count = (rand() % (max_boxes - 2)) + 2;
        game->map = generate_random_map(game->width, game->height, box_count);
    } else {
        game->height = count_line(argv[1]);
        game->width = get_max_length(argv[1]);
        load_map(argv[1], game);
    }
}

int init_game(game_t *game, char **argv)
{
    int max_boxes = 0;
    int box_count = 0;

    game->map = NULL;
    game->map_copy = NULL;
    game->player_x = 0;
    game->player_y = 0;
    game->box_count = 0;
    game->storage_count = 0;
    game->valid_boxes = 0;
    game->move_count = 0;
    choose_flags(argv, game, max_boxes, box_count);
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
