/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int game_loop(game_t *game)
{
    int ch = 0;

    display_map(game);
    while (check_win(game) == 0) {
        ch = getch();
        if (ch == 'q')
            break;
        if (ch == ' ')
            reset_game(game);
        check_player_move(ch, game);
        display_map(game);
        usleep(10000);
        print_lose(game);
    }
    return 0;
}

void free_map(char **map, int height)
{
    if (!map)
        return;
    for (int i = 0; i < height; i++)
        free(map[i]);
    free(map);
}

int run_csfml_mode(game_t *game)
{
    game->start_time = time(NULL);
    init_csfml(game);
    csfml_game_loop(game);
    free_csfml_cells(game);
    free_map(game->map, game->height);
    free_map(game->map_copy, game->height);
    free(game);
    return 0;
}

int run_ncurses_mode(game_t *game)
{
    init_ncurses();
    game->start_time = time(NULL);
    game_loop(game);
    print_win(game);
    endwin();
    free_map(game->map, game->height);
    free_map(game->map_copy, game->height);
    free(game);
    return 0;
}

int main(int argc, char **argv)
{
    game_t *game = NULL;

    if (argc_error_handling(argc, argv) == 84)
        return 84;
    game = malloc(sizeof(game_t));
    if (game == NULL)
        return 84;
    init_game(game, argv);
    if (error_handling(game) == 84)
        return 84;
    if (argc > 2 && have_csfml_flag(argc, argv) == 1) {
        return run_csfml_mode(game);
    } else {
        return run_ncurses_mode(game);
    }
}
