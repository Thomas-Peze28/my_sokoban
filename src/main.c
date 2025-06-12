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
    init_ncurses();
    game_loop(game);
    print_win(game);
    endwin();
    free_map(game->map, game->height);
    free_map(game->map_copy, game->height);
    free(game);
    return 0;
}
