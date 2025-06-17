/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

void draw_cell(game_t *game, int coords[2], float cell_size,
    float offsets[2])
{
    int x = coords[0];
    int y = coords[1];
    float offset_x = offsets[0];
    float offset_y = offsets[1];
    char cell = game->map[y][x];
    sfRectangleShape *rect = game->csfml->cells[y][x];
    sfVector2f position = {
        offset_x + x * cell_size,
        offset_y + y * cell_size
    };

    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, (sfVector2f){cell_size, cell_size});
    sfRectangleShape_setFillColor(rect, get_csfml_color(cell));
    sfRenderWindow_drawRectangleShape(game->csfml->window, rect, NULL);
}

int display_map_csfml(game_t *game)
{
    float cell_size = WIN_WIDTH / (float)game->width;
    float cell_size_h = WIN_HEIGHT / (float)game->height;
    float offset_x = 0.0;
    float offset_y = 0.0;

    if (cell_size_h < cell_size)
        cell_size = cell_size_h;
    offset_x = (WIN_WIDTH - (cell_size * game->width)) / 2.0f;
    offset_y = (WIN_HEIGHT - (cell_size * game->height)) / 2.0f;
    for (int y = 0; y < game->height; y++) {
        for (int x = 0; game->map[y][x] != '\0' && x < game->width; x++) {
            draw_cell(game, (int[2]){x, y}, cell_size,
            (float[2]){offset_x, offset_y});
        }
    }
    return 0;
}

void anazlyze_event(game_t *game)
{
    if (game->csfml->event.type == sfEvtClosed) {
        sfRenderWindow_close(game->csfml->window);
        return;
    }
    if (game->csfml->event.type == sfEvtKeyPressed) {
        if (game->csfml->event.key.code == sfKeyQ)
            sfRenderWindow_close(game->csfml->window);
        if (game->csfml->event.key.code == sfKeyUp)
            move_player(game, -1, 0);
        if (game->csfml->event.key.code == sfKeyDown)
            move_player(game, 1, 0);
        if (game->csfml->event.key.code == sfKeyLeft)
            move_player(game, 0, -1);
        if (game->csfml->event.key.code == sfKeyRight)
            move_player(game, 0, 1);
        if (game->csfml->event.key.code == sfKeySpace)
            reset_game(game);
    }
    return;
}

int csfml_game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->csfml->window)) {
        while (sfRenderWindow_pollEvent(game->csfml->window,
            &game->csfml->event)) {
            anazlyze_event(game);
        }
        sfRenderWindow_clear(game->csfml->window, sfColor_fromRGB(50, 50, 50));
        display_map_csfml(game);
        sfRenderWindow_display(game->csfml->window);
    }
    return 0;
}
