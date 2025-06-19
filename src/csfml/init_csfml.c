/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int have_csfml_flag(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-csfml") == 0)
            return 1;
    }
    return 0;
}

void init_font(game_t *game)
{
    game->csfml->font = sfFont_createFromFile("assets/Roboto-Black.ttf");
    game->csfml->text = sfText_create();
    sfText_setFont(game->csfml->text, game->csfml->font);
    sfText_setCharacterSize(game->csfml->text, 24);
    sfText_setFillColor(game->csfml->text, sfWhite);
}

void init_texture(game_t *game)
{
    game->csfml->wall_texture = sfTexture_createFromFile(
        "assets/wall.png", NULL);
    game->csfml->player_texture = sfTexture_createFromFile(
        "assets/player.png", NULL);
    game->csfml->box_texture = sfTexture_createFromFile(
        "assets/box.png", NULL);
    game->csfml->storage_texture = sfTexture_createFromFile(
        "assets/storage.png", NULL);
    game->csfml->floor_texture = sfTexture_createFromFile(
        "assets/floor.png", NULL);
    game->csfml->cells_sprites = malloc(sizeof(sfSprite**) * game->height);
    for (int y = 0; y < game->height; y++) {
        game->csfml->cells_sprites[y] = malloc(
            sizeof(sfSprite*) * game->width);
        for (int x = 0; x < game->width; x++) {
            game->csfml->cells_sprites[y][x] = sfSprite_create();
        }
    }
}

int init_csfml(game_t *game)
{
    game->csfml = malloc(sizeof(csfml_t));
    if (!game->csfml)
        return 84;
    game->csfml->width = WIN_WIDTH;
    game->csfml->height = WIN_HEIGHT;
    game->csfml->window = sfRenderWindow_create(
        (sfVideoMode){WIN_WIDTH, WIN_HEIGHT, 32},
        "Sokoban", sfResize | sfClose, NULL);
    if (!game->csfml->window)
        return 84;
    init_texture(game);
    init_font(game);
    return 0;
}
