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
    game->csfml->cells = malloc(sizeof(sfRectangleShape*) * game->height);
    for (int y = 0; y < game->height; y++) {
        game->csfml->cells[y] = malloc(sizeof(sfRectangleShape*)
            * game->width);
        for (int x = 0; x < game->width; x++) {
            game->csfml->cells[y][x] = sfRectangleShape_create();
        }
    }
    init_font(game);
    return 0;
}
