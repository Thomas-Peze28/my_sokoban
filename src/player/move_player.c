/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

void play_sound(const char *filename)
{
    pid_t pid = fork();

    if (pid == 0) {
        execlp("aplay", "aplay", "-q", filename, NULL);
    }
}

int check_if_storage(game_t *game)
{
    if (game->map_copy[game->player_y][game->player_x] == 'O')
        game->map[game->player_y][game->player_x] = 'O';
    else
        game->map[game->player_y][game->player_x] = ' ';
    return 0;
}

int check_box_move(game_t *game, int coords[2], int delta[2])
{
    int new_y = coords[0];
    int new_x = coords[1];
    int dy = delta[0];
    int dx = delta[1];
    int box_y = new_y + dy;
    int box_x = new_x + dx;

    if (game->map[new_y][new_x] != 'X')
        return 0;
    if ((game->map[box_y][box_x] == ' ' || game->map_copy[box_y][box_x] == 'O')
        && game->map[box_y][box_x] != 'X') {
        game->map[box_y][box_x] = 'X';
        check_if_storage(game);
        game->move_count++;
    } else {
        play_sound("assets/collision.wav");
        return 1;
    }
    return 0;
}

void move_player(game_t *game, int dy, int dx)
{
    int new_coords[2] = {game->player_y + dy, game->player_x + dx};
    int dir_coords[2] = {dy, dx};

    if (game->map[new_coords[0]][new_coords[1]] == '#') {
        play_sound("assets/collision.wav");
        return;
    }
    if (check_box_move(game, new_coords, dir_coords) == 1)
        return;
    check_if_storage(game);
    game->map[new_coords[0]][new_coords[1]] = 'P';
    game->player_y = new_coords[0];
    game->player_x = new_coords[1];
    play_sound("assets/footstep.wav");
    game->move_count++;
}
