/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

sfColor get_csfml_color(char cell)
{
    if (cell == '#')
        return sfColor_fromRGB(200, 0, 0);
    if (cell == 'P')
        return sfColor_fromRGB(0, 200, 0);
    if (cell == 'X')
        return sfColor_fromRGB(200, 200, 0);
    if (cell == 'O')
        return sfColor_fromRGB(0, 0, 200);
    if (cell == ' ' || cell == '\n')
        return sfColor_fromRGB(50, 50, 50);
    return sfColor_fromRGB(255, 255, 255);
}
