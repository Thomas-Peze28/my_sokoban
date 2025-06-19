/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

void choose_texture(game_t *game, char cell, sfSprite *sprite)
{
    if (cell == '#')
        sfSprite_setTexture(sprite, game->csfml->wall_texture, sfTrue);
    if (cell == 'P')
        sfSprite_setTexture(sprite, game->csfml->player_texture, sfTrue);
    if (cell == 'X')
        sfSprite_setTexture(sprite, game->csfml->box_texture, sfTrue);
    if (cell == 'O')
        sfSprite_setTexture(sprite, game->csfml->storage_texture, sfTrue);
    if (cell == ' ')
        sfSprite_setTexture(sprite, game->csfml->floor_texture, sfTrue);
    return;
}

void draw_cell(game_t *game, int coords[2], float cell_size, float offsets[2])
{
    int x = coords[0];
    int y = coords[1];
    float offset_x = offsets[0];
    float offset_y = offsets[1];
    char cell = game->map[y][x];
    sfSprite *sprite = game->csfml->cells_sprites[y][x];
    sfVector2f position = {
        offset_x + x * cell_size,
        offset_y + y * cell_size
    };
    sfVector2f scale = {cell_size / 64.0f, cell_size / 64.0f};

    choose_texture(game, cell, sprite);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(game->csfml->window, sprite, NULL);
}
