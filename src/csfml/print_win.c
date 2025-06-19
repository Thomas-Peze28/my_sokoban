/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int print_win_csfml(game_t *game)
{
    sfText *text = NULL;
    sfFont *font = NULL;

    if (check_win(game) != 1)
        return 0;
    text = sfText_create();
    font = sfFont_createFromFile("assets/Roboto-Black.ttf");
    sfText_setFont(text, font);
    sfText_setString(text, "You Win !");
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){
        WIN_WIDTH / 2 - 100, WIN_HEIGHT / 2 - 25});
    sfRenderWindow_drawText(game->csfml->window, text, NULL);
    sfRenderWindow_display(game->csfml->window);
    play_sound("assets/victory.wav");
    sleep(2);
    sfText_destroy(text);
    sfFont_destroy(font);
    return 1;
}
